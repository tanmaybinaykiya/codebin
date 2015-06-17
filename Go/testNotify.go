package main

import (
	"fmt"
	"github.com/bitly/go-notify"
	"time"
	// "math"
)

// producer of "my_event"
func main() {
	go func() {
		for {
			time.Sleep(time.Duration(2) * time.Second)
			notify.Post("my_event", "orig")
		}
	}()
	someVar := 3
	// observer of "my_event" (normally some independent component that
	// needs to be notified when "my_event" occurs)
	myEventChan := make(chan interface{})
	notify.Start("my_event", myEventChan)
	go func() {
		for {
			data := <-myEventChan

			fmt.Println("MY_EVENT: ", data, someVar)
			someVar += 2
			if someVar%3 == 0 {
				notify.Post("my_event", "fake")
			}
		}
	}()

	// go func() {
	// 	for {
	// 		time.Sleep(time.Duration(1) * time.Second)
	// 		 someVar++
	// 	}
	// }()

	myEventChan2 := make(chan interface{})
	notify.Start("my_event", myEventChan2)

	go func() {
		for {
			data := <-myEventChan2
			fmt.Println("MY_EVENT2: ", data, someVar)
			someVar *= 5
		}
	}()
	time.Sleep(time.Duration(100) * time.Second)
}
