#!/bin/bash 

set -e 

BUILD="build"


echo "build project..."

mkdir -p "BUILD"

cd "BUILD"

cmake ..

make

echo "build complete !"

echo"to run the app : "
echo"./QtLoginaApp"
