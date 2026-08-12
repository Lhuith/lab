package utils

import "errors"

// #meta#
// service: other
// !meta!
func Test() {
	LogMetaError(errors.New("other logging meta area"))
}

// #meta#
// service: another one
// !meta!
func Test2() {
	LogMetaError(errors.New("other logging meta area"))
}
