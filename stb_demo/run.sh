#! /bin/bash

set -e

gcc 1_hello_stb.c logger/log.c -lm -DLOG_USE_COLOR

./a.out
