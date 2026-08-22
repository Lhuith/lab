package service

import (
	"errors"
	"stacktest/utils"
)

func basicCall() {
	utils.LogMetaError(errors.New("doing a logging test"))
}
