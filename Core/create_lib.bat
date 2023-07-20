@echo off

dumpbin /exports nwserver.exe > nwserver.exports

echo LIBRARY nwserver.exe > nwserver.def
echo EXPORTS >> nwserver.def
for /f "skip=19 tokens=1,4" %%A in (nwserver.exports) do if NOT "%%B" == "" (echo %%B @%%A >> nwserver.def)

lib /def:nwserver.def /out:nwserver.lib /machine:x64 /name:nwserver.exe

del nwserver.exports nwserver.def nwserver.exp
