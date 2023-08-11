#!/bin/bash

#Cleanup macro comments left by SWIG.
for f in out/*.cs
do
  sed -i 's/\/\*@SWIG.*\*\///' "$f"
done
