package utils

import (
	"fmt"
	"runtime"
	"stacktest/meta"
	"strings"
)

// var SourcesCache sync.Map

const (
	metaStart = "#meta#"
	metaEnd   = "!meta!"
)

type (
	Frame struct {
		Function string
		File     string
		Line     int
		Meta     meta.Meta
	}
)

func Capture() []Frame {
	var pcs [32]uintptr

	// 0 - runtime.Callers
	// 1 - Capture
	// 2 - caller of Capture
	n := runtime.Callers(2, pcs[:])
	frames := runtime.CallersFrames(pcs[:n])

	var result []Frame
	for {
		frame, more := frames.Next()
		meta := lookUpMetaData(
			frame.File,
			frame.Function,
			frame.Line,
		)

		result = append(result, Frame{
			Function: frame.Function,
			File:     frame.File,
			Line:     frame.Line,
			Meta:     meta,
		})

		if !more {
			break
		}
	}

	return result
}

// returns first/nearest frame with metadata
// func meta -> file meta -> next frame -> func meta
func Nearest(frames []Frame) (Frame, bool) {
	for _, frame := range frames {
		if !frame.Meta.Empty() {
			return frame, true
		}
	}
	return Frame{}, false
}

func LogMetaError(err error) {
	if err == nil {
		return
	}
	frames := Capture()
	fmt.Println(FormatError(err, frames))
}

func FormatError(err error, frames []Frame) string {
	var b strings.Builder

	b.WriteString("----------\n")
	b.WriteString("ERROR: ")
	fmt.Fprintf(&b, "%v\n", err)

	if frame, ok := Nearest(frames); ok {
		// b.WriteString("OWNER\n")
		b.WriteString("----------\n")

		if frame.Meta.Service != "" {
			fmt.Fprintf(&b, "service: %s\n", frame.Meta.Service)
		}
		if frame.Meta.Operation != "" {
			fmt.Fprintf(&b, "operation: %s\n", frame.Meta.Operation)
		}
		fmt.Fprintf(&b, "function: %s\n", frame.Function)
		fmt.Fprintf(&b, "location: %s:%d\n", frame.File, frame.Line)
	}

	//b.WriteString("STACK\n")
	//b.WriteString("-------------\n")

	//for i, frame := range frames {
	//	fmt.Fprintf(&b, "#%d %s\n", i, frame.Function)
	//	fmt.Fprintf(&b, "		%s:%d\n", frame.File, frame.Line)

	//	if !frame.Meta.Empty() {
	//		if frame.Meta.Service != "" {
	//			fmt.Fprintf(&b, "	service: %s\n", frame.Meta.Service)
	//		}
	//		if frame.Meta.Operation != "" {
	//			fmt.Fprintf(&b, "	operation: %s\n", frame.Meta.Operation)
	//		}
	//	}
	//	b.WriteString("\n")
	//}
	return b.String()
}

func lookUpMetaData(file, function string, line int) meta.Meta {
	// function level
	for _, entry := range GeneratedMeta {
		if entry.File != file {
			continue
		}
		if entry.Function == function ||
			strings.HasSuffix(function, "."+entry.Function) {
			return entry.Meta
		}
	}

	// file level
	for _, entry := range GeneratedFileMeta {
		if entry.File == file {
			return entry.Meta
		}
	}

	return meta.Meta{}

	//value, ok := SourcesCache.Load(fileName)

	//if !ok {
	//	source := parseSourceFile(fileName)
	//	SourcesCache.Store(fileName, source)
	//	value = source
	//}
	//source := value.(SourceMeta)

	//// func meta wins
	//if meta, ok := source.Functions[function]; ok {
	//	return meta
	//}

	//for name, meta := range source.Functions {
	//	if strings.HasSuffix(function, "."+name) {
	//		return meta
	//	}
	//}

	//// file-level metadata
	//return source.FileMeta
}

// func RunTimeParseSourceFile(fileName string) SourceMeta {
// 	result := SourceMeta{
// 		Functions: make(map[string]Meta),
// 	}
//
// 	file, err := os.Open(fileName)
// 	if err != nil {
// 		return result
// 	}
//
// 	defer file.Close()
//
// 	var pending *Meta
//
// 	scanner := bufio.NewScanner(file)
//
// 	for scanner.Scan() {
// 		line := strings.TrimSpace(scanner.Text())
//
// 		if line == "// "+metaStart {
// 			meta := readMetaDataBlock(scanner)
// 			pending = &meta
// 			continue
// 		}
// 		if pending == nil {
// 			continue
// 		}
//
// 		// meta before func
// 		if strings.HasPrefix(line, "func ") {
// 			name := functionName(line)
// 			if name != "" {
// 				result.Functions[name] = *pending
// 			}
// 			pending = nil
// 			continue
// 		}
//
// 		// otherwise treat as metadata
// 		if line != "" && !strings.HasPrefix(line, "//") {
// 			if result.FileMeta.Empty() {
// 				result.FileMeta = *pending
// 			}
// 			pending = nil
// 		}
// 	}
//
// 	return result
// }

// readMetaDataBlock
/*
	#meta#
		service: serviceX
		operation: auth
	!meta!
*/
//func readMetaDataBlock(scanner *bufio.Scanner) Meta {
//	meta := Meta{
//		Values: make(map[string]string),
//	}
//	for scanner.Scan() {
//		line := strings.TrimSpace(scanner.Text())
//
//		if line == "// "+metaEnd {
//			break
//		}
//		line = strings.TrimPrefix(line, "//")
//		line = strings.TrimSpace(line)
//
//		if line == "" {
//			continue
//		}
//		parts := strings.SplitN(line, ":", 2)
//		if len(parts) != 2 {
//			continue
//		}
//		key := strings.TrimSpace(parts[0])
//		value := strings.TrimSpace(parts[1])
//		meta.Values[key] = value
//
//		switch key {
//		case "service":
//			meta.Service = value
//		case "operation":
//			meta.Operation = value
//		}
//	}
//	return meta
//}

// get function name
// swap out for pre-generated later on
func functionName(line string) string {
	line = strings.TrimPrefix(line, "func ")
	line = strings.TrimSpace(line)

	index := strings.Index(line, "(")

	if index >= 0 {
		return line[:index]
	}

	return ""
}
