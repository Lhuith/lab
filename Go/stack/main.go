// #meta#
// service: test
// !meta!
package main

import (
	"errors"
	utils "stacktest/utils"
)

// #meta#
// service: test2-override
// operation: making a override call
// !meta!
func main() {
	residentialCall()
	utils.LogMetaError(errors.New("this is an error"))
	utils.Test()
	utils.Test2()
}

// #meta#
// service: residential
// operation: making a call
// !meta!
func residentialCall() {
	utils.LogMetaError(errors.New("this is an error"))
}
