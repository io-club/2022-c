#! /bin/bash

set -e

gcc main.c logger/log.c cmd.c -lm -DLOG_USE_COLOR
