package main

import (
	"fmt"
	"log"
	"net/http"
	"os"
	Monitor "scratch/monitor"
	Routes "scratch/routes"
	"scratch/utils"

	"github.com/prometheus/client_golang/prometheus/promhttp"
)

func main() {
	Monitor.RecordMetrics()

	fmt.Println(os.Getenv("ENV"))
	fmt.Println("MiniKube, MiniGopher")

	http.HandleFunc("/", func(w http.ResponseWriter, r *http.Request) {
		fmt.Fprint(w, `<h1 style='text-align:center;'>Welcome to Minikube Scratch Service</h1>`+utils.Monke)
	})

	http.HandleFunc("/a", Routes.FakeResponse("a route"))
	http.HandleFunc("/b", Routes.FakeResponse("b route"))
	http.HandleFunc("/c", Routes.FakeResponse("c route"))
	http.HandleFunc("/d", Routes.FakeResponse("d route"))

	// promethues metrics tester
	http.Handle("/metrics", promhttp.Handler())

	http.HandleFunc("/replace", func(w http.ResponseWriter, r *http.Request) {
		fmt.Fprintf(w, "replace == %v\n", os.Getenv("REPLACE"))
	})

	http.HandleFunc("/env", func(w http.ResponseWriter, r *http.Request) {
		fmt.Fprint(w, os.Getenv("ENV")+"\n")
	})

	log.Fatal(http.ListenAndServe(":8080", nil))
}
