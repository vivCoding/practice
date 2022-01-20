#!/bin/bash

OUTDIR=./bin

fullfilename=$1
filename=$(basename "$fullfilename")
filename="${filename%.*}"

mkdir -p $OUTDIR
echo "Compiling..."
g++ -o $OUTDIR/$filename $1
echo "Compilation finished. Running.."
exec $OUTDIR/$filename