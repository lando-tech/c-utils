#!/bin/bash

cmake -B build
cd build && make
./bin/c-utils
