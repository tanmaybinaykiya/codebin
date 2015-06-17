package main

import (
	"fmt"
	"github.com/deckarep/golang-set"
	"math/rand"
	"time"
)

type node struct {
	x int
	y int
}

//Returns neighbours of @root

var fullSet mapset.Set
var blockedSet mapset.Set
var solutionSet mapset.Set
var MAX int

func square(x int) int {
	return x * x
}

func showGrid(start, goal node) {

	for j := MAX - 1; j >= 0; j-- {
		for i := 0; i < MAX; i++ {
			pt := node{x: i, y: j}
			if i == start.x && j == start.y {
				fmt.Printf("S ")
			} else if i == goal.x && j == goal.y {
				fmt.Printf("G ")
			} else if blockedSet.Contains(pt) {
				fmt.Printf("  ")
			} else if solutionSet.Contains(pt) {
				fmt.Printf("* ")
			} else if fullSet.Contains(pt) {
				fmt.Printf("O ")
			} else {
				fmt.Printf(". ")
			}

		}
		fmt.Println()
	}

}

func (root node) neighbours(fullSet mapset.Set) mapset.Set {
	neighbours := mapset.NewSet()
	for currNode := range fullSet.Iter() {
		if someNode, ok := currNode.(node); ok {
			if ((square(someNode.x-root.x) < 1) && (square(someNode.y-root.y) <= 1)) || ((square(someNode.x-root.x) <= 1) && (square(someNode.y-root.y) < 1)) {
				if !blockedSet.Contains(someNode) {
					neighbours.Add(someNode)
				}
			}
		} else {
			fmt.Println("Invalid object added ", currNode, " ", currNode.(node))
		}
	}
	return neighbours
}

func heuristic_cost_estimate(start, goal node) int {
	rand.Seed(time.Now().UnixNano())
	sign := rand.Intn(2)
	if sign == 1 {
		return (start.x-goal.x)*(start.x-goal.x) + (start.y-goal.y)*(start.y-goal.y)
	} else {
		return (start.x-goal.x)*(start.x-goal.x) + 2*(start.y-goal.y)*(start.y-goal.y)
	}

}

func lowestFScore(openSet mapset.Set, f_score map[node]int) node {
	minVal := 500
	var minNode node
	for currNode := range openSet.Iter() {
		if someNode, ok := currNode.(node); ok {
			if f_score[someNode] < minVal {
				minVal = f_score[someNode]
				minNode = someNode

			}
		} else {
			fmt.Println("Invalid object added ", currNode, " ", currNode.(node))

		}

	}
	return minNode
}

func (nodes node) String() string {
	return fmt.Sprintf("{%d,%d}", nodes.x, nodes.y)
}

func reconstruct_path(came_from map[node]node, current node) []node {
	// fmt.Println("reconstruct_path", current)
	var total_path []node
	total_path = append(total_path, current)
	solutionSet.Add(current)
	var ok bool
	for current, ok = came_from[current]; ok; {
		if current != came_from[current] {
			// fmt.Println("came_from[", current, "]=", came_from[current])
			total_path = append(total_path, current)
			solutionSet.Add(current)
			current = came_from[current]
		} else {
			break
		}
	}
	total_path = append(total_path, current)
	solutionSet.Add(current)
	// fmt.Println("returning")
	return total_path
}

func dist_between(current, neighbour node) int {
	return 1
}

func aStar(start, goal node) (path []node, err bool) {
	closedSet := mapset.NewSet()
	openSet := mapset.NewSet()
	openSet.Add(start)
	came_from := make(map[node]node)
	delete(came_from, start)
	// fmt.Println("came_from[", start, "]=", came_from[start])
	g_score := make(map[node]int) //should contain all nodes
	f_score := make(map[node]int) //should contain all nodes

	g_score[start] = 0
	f_score[start] = g_score[start] + heuristic_cost_estimate(start, start)
	// fmt.Println("before For")
	for openSet.Cardinality() != 0 {
		current := lowestFScore(openSet, f_score)
		// fmt.Println("Current: ", current)
		if current == goal {
			return reconstruct_path(came_from, goal), true
		}

		openSet.Remove(current)
		closedSet.Add(current)
		for someNode := range current.neighbours(fullSet).Iter() {
			if neighbour, ok := someNode.(node); ok {
				if closedSet.Contains(neighbour) {
					continue
				}
				var tentative_g_score int
				tentative_g_score = g_score[current] + dist_between(current, neighbour)

				if !openSet.Contains(neighbour) || tentative_g_score < g_score[neighbour] {
					// fmt.Println("came_from[", neighbour, "] = ", current)
					came_from[neighbour] = current
					g_score[neighbour] = tentative_g_score
					f_score[neighbour] = g_score[neighbour] + heuristic_cost_estimate(neighbour, goal)
					if !openSet.Contains(neighbour) {
						openSet.Add(neighbour)
					}
				}
			}
		}

	}
	return nil, false
}

func main() {

	fullSet = mapset.NewSet()
	blockedSet = mapset.NewSet()
	solutionSet = mapset.NewSet()
	MAX = 10
	start := node{0, 0}
	goal := node{MAX - 1, MAX - 1}
	for i := 0; i < MAX; i++ {
		for j := 0; j < MAX; j++ {
			fullSet.Add(node{x: i, y: j})
		}
	}

	for i := 0; i < MAX-1; i++ {
		blockedSet.Add(node{x: i, y: 1})
		// blockedSet.Add(node{x: i, y: 5})
	}
	for i := 1; i < MAX; i++ {
		blockedSet.Add(node{x: i, y: 3})
		// blockedSet.Add(node{x: i, y: 7})
	}

	if path, ok := aStar(start, goal); ok {
		fmt.Println(path)
		fmt.Println("Total cost = ", len(path))
	} else {
		fmt.Println("No Path Found")
	}
	showGrid(start, goal)
}
