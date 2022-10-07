#! /bin/bash

set -e

gcc hello_stb.c log.c/src/log.c -lm -DLOG_USE_COLOR

./a.out
