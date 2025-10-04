package Routes

import (
	"fmt"
	"net/http"
	Monitor "scratch/monitor"

	"github.com/prometheus/client_golang/prometheus"
	"github.com/prometheus/client_golang/prometheus/promauto"
)

var (
	requestPing = promauto.NewCounterVec(
		prometheus.CounterOpts{
			Name: "route ping",
			Help: "leave me alone",
		},
		[]string{"route code"},
	)
	FakeResponse = func(m string) func(w http.ResponseWriter, r *http.Request) {
		return func(w http.ResponseWriter, r *http.Request) {
			requestPing.WithLabelValues(m).Inc()
			fmt.Fprint(w, m+"\n")
		}
	}
)

func Ping(w http.ResponseWriter, r *http.Request) {
	// https://stackoverflow.com/questions/34314975/go-get-path-parameters-from-http-request
	// tanks Awacate
	fmt.Println("Ping!", r.PathValue("msg"))
	fmt.Fprintf(w, "<p>%v</p>", r.PathValue("msg"))
	Monitor.PingMetric(r.PathValue("msg"))
}

func init() {
	//prometheus.MustRegister(requestPing)
}
