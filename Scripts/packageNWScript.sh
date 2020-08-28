#!/bin/bash

echo "Zipping NWScripts..."
zip -j Binaries/NWScript.zip `find . -name "*.nss" -not -path "./build-nwnx/*" | grep -Pv '_t+[0-9]{0,1}.nss'` > /dev/null
