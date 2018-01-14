#!/bin/bash


for i in `find . -name NWScript`; do
    scriptdir=`dirname $i`
    folder=Binaries/NWScript/`basename $scriptdir`

    mkdir -p $folder
    for n in $i/*.nss; do
        if [[ `basename $n` != *_t.nss ]]; then
            cp $n $folder/`basename $n`
        fi
    done 
done

pushd Binaries

zip -r NWScript.zip NWScript

pushd NWScript
for i in `find . -name *.nss`; do
    rm $i 
done
for d in *; do
    rmdir -p $d
done
popd
rmdir -p NWScript

popd