#!/bin/bash


for i in `find . -name NWScript`; do
    scriptdir=`dirname $i`
    folder=Binaries/NWScript/`basename $scriptdir`

    mkdir -p $folder
    for n in $i/*.nss; do
        if [[ ! `basename $n` =~ (_t+[0-9]{0,1}.nss) ]]; then
            cp $n $folder/`basename $n`
        fi
    done 
done

pushd Binaries >> /dev/null

mkdir -p Tests
TESTS=$(find .. -name "*_t.nss")
cp $TESTS ./Tests

echo "void main() {" > Tests/nwnx_t.nss
for f in $TESTS; do
    echo "    ExecuteScript(\"`basename $f .nss`\", OBJECT_SELF);" >> Tests/nwnx_t.nss
done
echo "}" >> Tests/nwnx_t.nss

echo "Zipping NWScripts..."
zip -FSr NWScript.zip Tests NWScript > /dev/null
rm -r ./Tests
rm -r ./NWScript

popd >> /dev/null