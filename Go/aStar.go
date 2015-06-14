package main

/*
*function A*(start,goal)
*    closedset := the empty set    // The set of nodes already evaluated.
*    openset := {start}    // The set of tentative nodes to be evaluated, initially containing the start node
*    came_from := the empty map    // The map of navigated nodes.
*
*    g_score[start] := 0    // Cost from start along best known path.
*    // Estimated total cost from start to goal through y.
*    f_score[start] := g_score[start] + heuristic_cost_estimate(start, goal)
*
*    while openset is not empty
*        current := the node in openset having the lowest f_score[] value
*        if current = goal
*            return reconstruct_path(came_from, goal)
*
*        remove current from openset
*        add current to closedset
*        for each neighbor in neighbor_nodes(current)
*            if neighbor in closedset
*                continue
*            tentative_g_score := g_score[current] + dist_between(current,neighbor)
*
*            if neighbor not in openset or tentative_g_score < g_score[neighbor]
*                came_from[neighbor] := current
*                g_score[neighbor] := tentative_g_score
*                f_score[neighbor] := g_score[neighbor] + heuristic_cost_estimate(neighbor, goal)
*                if neighbor not in openset
*                    add neighbor to openset
*
*    return failure
*
*function reconstruct_path(came_from,current)
*    total_path := [current]
*    while current in came_from:
*        current := came_from[current]
*        total_path.append(current)
*    return total_path
 */

import (
	"fmt"
	"github.com/deckarep/golang-set"
	// "math"
)

type node struct {
	x int
	y int
}

func heuristic_cost_estimate(start, goal node) int {
	return (start.x-goal.x)*(start.x-goal.x) + (start.y-goal.y)*(start.y-goal.y)
}

func lowestFScore(openSet mapset.Set, f_score map[node]int) node {
	minVal := 500
	var minNode node
	// for currNode := range openSet.Iter() {
	// 	if currNode, ok := openSet.Iter(); ok {
	// 		/* act on node */
	// 		if f_score[currNode] < minVal {
	// 			minVal = f_score[currNode]
	// 			minNode = currNode
	// 		}
	// 	} else {
	// 		/* not node */
	// 		fmt.Println("Not Node")
	// 	}
	}
	return minNode
}

func aStar(start, goal node) {
	closedSet := mapset.NewSet()
	openSet := mapset.NewSet()
	openSet.Add(start)
	came_from := make(map[node]node)
	g_score := make(map[node]int)
	f_score := make(map[node]int)

	g_score[start] = 0
	f_score[start] = g_score[start] + heuristic_cost_estimate(start, start)

	for openSet.Cardinality() != 0 {
		current := lowestFScore(openSet, f_score)
	}

}

func main() {

}
