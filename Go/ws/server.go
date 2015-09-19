package main

import (
	"fmt"
	"github.com/gorilla/websocket"
	"net/http"
	"strings"
	"time"
)

type HTTPHandler struct{}

type Connection struct {
	wsConn           *websocket.Conn
	heartBeatChannel chan string
	messageChannel   chan string
}

var upgrader = websocket.Upgrader{
	CheckOrigin:     func(r *http.Request) bool { return true },
	ReadBufferSize:  1024,
	WriteBufferSize: 1024,
}

var pongMessage = "primus::pong"
var pingMessage = "primus::ping"

func GetPongMessage() string {
	return fmt.Sprintf("primus::pong:%d", time.Now().UnixNano()/int64(time.Millisecond))
}

func (conn Connection) HBHandler() {
	timer := time.NewTimer(5 * time.Second)
	go func() {
		for {
			select {
			case <-conn.heartBeatChannel:
				val := timer.Reset(5 * time.Second)
				if !val {
					conn.wsConn.Close()
				}
				conn.sendMessage(GetPongMessage())
			case <-timer.C:
				fmt.Println("Closing connection as heartbeat not sent in time")
				conn.wsConn.Close()
			}
		}
	}()
}

func (conn Connection) MessageHandler() {
	go func() {
		for {
			select {
			case <-conn.messageChannel:
				conn.sendMessage("Reply: " + <-conn.messageChannel)
			}
		}
	}()
}

func (conn Connection) WSListener() {
	for {
		messageType, message, err := conn.wsConn.ReadMessage()
		if err != nil {
			fmt.Println(err)
			return
		}
		if messageType == websocket.TextMessage {
			// fmt.Println("Message received\n")
			if strings.HasPrefix(string(message), pingMessage) {
				fmt.Printf("\t heartBeat Message: %s\n", message)
				conn.heartBeatChannel <- string(message)
			} else {
				fmt.Printf("\t regular Message: %s\n", message)
				conn.messageChannel <- string(message)
			}
		} else {
			fmt.Println("Binary Frame, not handling for now")
		}
	}
}

func (conn Connection) sendMessage(message string) {
	conn.wsConn.WriteMessage(websocket.TextMessage, []byte(message))
}

func (h HTTPHandler) ServeHTTP(w http.ResponseWriter, r *http.Request) {

	if r.Header.Get("Upgrade") == "websocket" {
		wconn, err := upgrader.Upgrade(w, r, nil)
		if err != nil {
			fmt.Println("err upgrading " + err.Error())
			return
		}
		fmt.Println("conn upgraded")
		heartBeatChannel := make(chan string)
		messageChannel := make(chan string)
		conn := Connection{wconn, heartBeatChannel, messageChannel}
		conn.HBHandler()
		conn.MessageHandler()
		conn.WSListener()
	} else {
		w.Write([]byte("Hi! This is Tanmay's server. You should not be meddling around here"))
	}
}

func main() {
	var h HTTPHandler
	err := http.ListenAndServe("localhost:4000", h)
	if err != nil {
		fmt.Println(err)
	}
}
