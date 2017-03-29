#!/bin/bash
# Get the size in bytes of URL content
curl -X GET -sI "$1" | grep 'Content-Length' | cut -d ' ' -f2
