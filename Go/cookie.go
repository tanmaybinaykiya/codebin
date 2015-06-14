package main

import (
	"fmt"
	"net/http"
	"time"
)

type String string

type Struct struct {
	Greeting string
	Punct    string
	Who      string
}

func (h Struct) ServeHTTP(w http.ResponseWriter, r *http.Request) {
	fmt.Fprint(w, h.Greeting+" "+r.RemoteAddr)
}

func (s String) ServeHTTP(w http.ResponseWriter, r *http.Request) {
	fmt.Println(r.Header)
	// w.Header().Add("Set-Cookie","foo=bar; Domain=foobar.com; Path=/path; Expires=Wed, 13 Jan 2021 22:23:01 GMT; Secure; HttpOnly");
	sessionCookie := http.Cookie{}
	sessionCookie.Name = "foo"
	sessionCookie.Value = "Bar"
	sessionCookie.Path = "foobar"
	sessionCookie.Domain = "foo.bar"
	const longForm = "Jan 2, 2006 at 3:04pm (MST)"
	sessionCookie.Expires, _ = time.Parse(longForm, "Jan 13, 2021 at 10:06pm (GMT)")
	sessionCookie.RawExpires = "Wed, 13 Jan 2021 22:23:01 GMT"
	http.SetCookie(w, &sessionCookie)
	// w.WriteHeader(201);
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
	http.ListenAndServe("localhost:4000", nil)
}
