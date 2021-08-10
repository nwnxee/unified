#!/bin/bash

usage() { echo "$0 usage:" && grep " .)\ #" $0; exit 0; }

CLEAN=

while getopts ":hcj:" o; do
    case "${o}" in
        c) # Clean build - remove Binaries and re-execute cmake
            CLEAN=-c
            ;;
        j) # Concurrent job count for the make command
            JOBS="-j $OPTARG"
            ;;
        h | *) # Display help
            usage
            exit 0
            ;;
    esac
done
shift $((OPTIND-1))

docker run --rm -w /nwnx/home --entrypoint "/bin/bash" -v "$(pwd):/nwnx/home" nwnxee/builder ./Scripts/buildnwnx.sh ${CLEAN} ${JOBS}
