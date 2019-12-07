#!/bin/bash

for i in `find . -name NWScript`; do
    scriptdir=`dirname $i`
    folder=Binaries/NWScript/`basename $scriptdir`

    if [ "$scriptdir" == "./Plugins/DotNET/NWN" ]; then
      continue
    fi

    mkdir -p $folder
    for n in $i/*.nss; do
        if [[ ! `basename $n` =~ (_t+[0-9]{0,1}.nss) ]]; then
            cp $n $folder/`basename $n`
        fi
    done
done

pushd Binaries

echo "Zipping NWScripts..."
zip -r NWScript.zip NWScript > /dev/null

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