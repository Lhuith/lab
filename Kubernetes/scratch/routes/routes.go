package Routes

import (
	"fmt"
	"net/http"
)

var (
	FakeResponse = func(m string) func(w http.ResponseWriter, r *http.Request) {
		return func(w http.ResponseWriter, r *http.Request) {
			fmt.Fprint(w, m+"\n")
		}
	}
)
