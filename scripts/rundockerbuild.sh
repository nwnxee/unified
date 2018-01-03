#!/bin/bash

usage() { echo "$0 usage:" && grep " .)\ #" $0; exit 0; }

CLEAN=

while getopts ":hc" o; do
    case "${o}" in
        c) # Clean build - remove Binaries and re-execute cmake
            CLEAN=-c
            ;;
        h | *) # Display help
            usage
            exit 0
            ;;
    esac
done
shift $((OPTIND-1))

docker run --rm -w /nwnx/home --entrypoint "/bin/bash" -v $(pwd):/nwnx/home docker.nwnx.io:443/nwnxee/unified:builder ./scripts/buildnwnx.sh ${CLEAN}