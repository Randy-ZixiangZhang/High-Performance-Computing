#!/bin/sh
mkdir -p build
cd build
rm ./HA
cmake .. -DCMAKE_BUILD_TYPE=Release
make
./HA
