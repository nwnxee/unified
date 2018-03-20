#!/bin/bash

pushd Plugins/JVM/java

ant jar

popd

cp Plugins/JVM/java/dist/org.nwnx.nwnx2.jvm.jar Binaries