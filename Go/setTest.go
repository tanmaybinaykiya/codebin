package main

import (
	"fmt"
	"github.com/deckarep/golang-set"
)

type node struct {
	x int
	y int
}

func printAll(testSet mapset.Set) {
	fmt.Println(testSet)
}

func iterateAll(testSet mapset.Set) {
	for currNode := range testSet.Iter() {
		if someNode, ok := currNode.(node); ok {
			fmt.Println("x: ", someNode.x, " y: ", someNode.y)
		} else {
			fmt.Println("lone: ", currNode)
		}
	}
}

func main() {
	testSet := mapset.NewSet()
	testSet.Add(node{x: 5, y: 6})
	testSet.Add(node{x: 7, y: 6})
	testSet.Add(5)
	fmt.Println(testSet[5])
	testSet.Add(node{x: 9, y: 6})
	iterateAll(testSet)
}
