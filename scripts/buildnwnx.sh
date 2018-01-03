#!/bin/bash

usage() { echo "$0 usage:" && grep " .)\ #" $0; exit 0; }

CLEAN=1

while getopts ":hc" o; do
    case "${o}" in
        c) # Clean build - remove Binaries and re-execute cmake
            CLEAN=0
            ;;
        h | *) # Display help
            usage
            exit 0
            ;;
    esac
done
shift $((OPTIND-1))

CC="gcc -m32" 
CXX="g++ -m32" 

if [ ${CLEAN} == 0 ]; then
    if [ -d ./Binaries ]; then
        echo "Removing Binaries" 
        rm -rf ./Binaries; 
    fi

    if [ -d ./build-nwnx ]; then 
        echo "Removing build-nwnx"
        rm -rf ./build-nwnx; 
    fi
fi

mkdir ./build-nwnx
cd ./build-nwnx

cmake -D CMAKE_BUILD_TYPE=RelWithDebInfo ..

make all
