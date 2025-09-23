package main

import (
	"fmt"
	"log"
	"net/http"
	"os"
)

func main() {
	fmt.Println(os.Getenv("ENV"))
	fmt.Println("MiniKube, MiniGopher")

	http.HandleFunc("/", func(w http.ResponseWriter, r *http.Request) {
		fmt.Fprintf(w, "testin\n")
	})

	http.HandleFunc("/a", func(w http.ResponseWriter, r *http.Request) {
		fmt.Fprintf(w, "a route\n")
	})

	http.HandleFunc("/b", func(w http.ResponseWriter, r *http.Request) {
		fmt.Fprintf(w, "b route\n")
	})

	http.HandleFunc("/replace", func(w http.ResponseWriter, r *http.Request) {
		fmt.Fprint(w, fmt.Sprintf("replace == %v\n", os.Getenv("REPLACE")))
	})

	http.HandleFunc("/env", func(w http.ResponseWriter, r *http.Request) {
		fmt.Fprint(w, os.Getenv("ENV")+"\n")
	})

	log.Fatal(http.ListenAndServe(":8080", nil))
}
