package main

import (
	"fmt"
	"log"
	"net/http"
)

type String string

type Struct struct{
	Greeting string
    Punct    string
    Who      string
}

func (h Struct) ServeHTTP(w http.ResponseWriter,r *http.Request){
	fmt.Fprint(w, h.Greeting+" "+r.RemoteAddr)
}

func (s String) ServeHTTP(w http.ResponseWriter,r *http.Request){
	fmt.Fprint(w, s)
}

// func (h Hello) ServeHTTP(w http.ResponseWriter,r *http.Request) {
	
// 	fmt.Println(r.Header["User-Agent"])
// 	fmt.Println(r.RemoteAddr)
// 	fmt.Println(r.RequestURI)
// 	if(r.RequestURI=="/test"){
// 		fmt.Fprint(w, "Success!")
// 	}else{
// 		fmt.Fprint(w, "Failed!")	
// 	}
// }

func main() {
	// var h Hello
	// err := http.ListenAndServe("localhost:4000", nil)
	// if err != nil {
	// 	log.Fatal(err)
	// }
	http.Handle("/string", String("I'm a frayed knot."))
	http.Handle("/struct", &Struct{"Hello", ":", "Gophers!"})
	log.Fatal(http.ListenAndServe("localhost:4000", nil))
}

