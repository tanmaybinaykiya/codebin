package main

import (
	"fmt"
	"github.com/gorilla/websocket"
	"net/http"
	"time"
)

type Hello struct{}

var upgrader = websocket.Upgrader{
	CheckOrigin:     func(r *http.Request) bool { return true },
	ReadBufferSize:  1024,
	WriteBufferSize: 1024,
}

func recHeartbeats(conn *websocket.Conn, recd chan []byte) {

	timer := time.NewTimer(5 * time.Second)

	go func() {
		for {
			select {
			case <-recd:
				fmt.Println("Saved by the ping")
				val := timer.Reset(5 * time.Second)
				if !val {
					conn.Close()
				}
			case <-timer.C:
				conn.Close()
				fmt.Printf("Closing connection as heartbeat not sent in time")
			}
		}
	}()
}

func readAndWrite(conn *websocket.Conn) error {
	recd := make(chan []byte)
	recHeartbeats(conn, recd)
	for {
		messageType, p, err := conn.ReadMessage()
		if err != nil {
			fmt.Println(err)
			return err
		}
		recd <- p
		if err = conn.WriteMessage(messageType, p); err != nil {
			fmt.Println(err)
			return err
		}
		fmt.Println("write:" + string(p))
	}
	return nil
}

func (h Hello) ServeHTTP(w http.ResponseWriter, r *http.Request) {
	fmt.Println("Hello!")
	conn, err := upgrader.Upgrade(w, r, nil)
	if err != nil {
		fmt.Println("err upgrading " + err.Error())
		return
	}
	fmt.Println("conn upgraded")
	readAndWrite(conn)
}

func main() {
	var h Hello
	err := http.ListenAndServe("localhost:4000", h)
	if err != nil {
		fmt.Println(err)
	}
}
