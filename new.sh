#!/bin/bash
dirname=$(dirname "$1")
mkdir -p $dirname
cp "_template_basic.cpp" "$1.cpp"
echo "Created file $1.cpp"