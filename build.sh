#!/bin/bash

echo "Linux compilation." 
cd Linux

if [ -d "build" ]; then
  echo "build directory already exists."
else
  mkdir build
fi

cd build
conan install .. --build=missing
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build . --clean-first

echo "Linux compilation ended."
echo

echo "Windows cross compilation."
cd ../../Windows

if [ -d "build"]; then
  echo "build directory already exists."
else
  mkdir build
fi

cd build
conan install .. --build=missing -pr:h windows -pr:b default
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build . --clean-first

cd ../..

echo "Windows cross compilation ended."

# Attention to conan profiles when compiling or cross compiling