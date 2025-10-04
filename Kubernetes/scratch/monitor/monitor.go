package Monitor

import (
	"fmt"
	"time"

	"github.com/prometheus/client_golang/prometheus"
	"github.com/prometheus/client_golang/prometheus/promauto"
)

var (
	pingMessageMetric = promauto.NewCounterVec(prometheus.CounterOpts{
		Name: "ping",
		Help: "giving me cron job a thing to do",
	}, []string{"message"})

	opsProcessed = promauto.NewCounter(prometheus.CounterOpts{
		Name: "scratch_processed_ops_total",
		Help: "The total number processed events",
	})
)

func PingMetric(m string) {
	pingMessageMetric.WithLabelValues(m).Inc()
}

func RecordMetrics() {
	fmt.Println("Goin Metric up in here")
	go func() {
		for {
			opsProcessed.Inc()
			time.Sleep(2 * time.Second)
		}
	}()
}
