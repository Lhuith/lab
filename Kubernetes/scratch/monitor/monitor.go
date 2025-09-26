package Monitor

import (
	"fmt"
	"time"

	"github.com/prometheus/client_golang/prometheus"
	"github.com/prometheus/client_golang/prometheus/promauto"
)

var (
	opsProcessed = promauto.NewCounter(prometheus.CounterOpts{
		Name: "scratch_processed_ops_total",
		Help: "The total number processed events",
	})
)

func RecordMetrics() {
	fmt.Println("Goin Metric up in here")
	go func() {
		for {
			fmt.Println("Metric Tick, For Sanity")
			opsProcessed.Inc()
			time.Sleep(2 * time.Second)
		}
	}()
}
