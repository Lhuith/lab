#!/bin/bash

#windows cmake run instructions
cmake -DBUILD_SHARED_LIBS=ON -DCMAKE_TOOLCHAIN_FILE=../cmakeTools/mingw-w64-x86_64.cmake ..