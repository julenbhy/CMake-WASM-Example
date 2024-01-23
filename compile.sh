#!/bin/bash

source_file="main_threads"

rm -rf "./build"

mkdir -p "./build"

cd "./build"

cmake ..

make

wasmtime -S threads $source_file.wasm
