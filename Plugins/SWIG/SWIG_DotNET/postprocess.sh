#!/bin/bash

#Cleanup macro comments left by SWIG.
for f in out/*.cs
do
  sed -i '/^[ \t]*\/\*@SWIG/d' "$f"
done
