Build instructions:

- mkdir build
- cd build
- cmake -DCMAKE_BUILD_TYPE=Release ../
- make -j 8

Dependencies

- Linux requires GCC 5.4.0+ or Clang 3.8+. Note that if you compile on Clang in debug mode you will segfault -- it generates incorrect assembly for the API jumps. Release mode works fine.
- Windows status is UNKNOWN. It will probably compile, but it will break at run-time.

Contribution guide:

- If you're making changes to the core, please follow the existing code style guide and code quality guide below.
- If you're submitting a plugin, do whatever you want, as long as you use the core services for your stuff when appropriate.

Core code style guide:

- Prefix members variables with m_.
- Use lowerCamelCase for variables.
- Use UpperCamelCase for functions.
- Use UpperCamelCase for classes.
- Use ALL_CAPS for constants and macros.
- Braces always start on a new line and always end on a new line.
- Spaces, not tabs.
- Avoid manual memory management. Use unique_ptr always.

Core code quality guide:

- Code with all possible platforms in mind.
- Code with transparent hotswappability in mind.
- Code with ease of use of developers in mind.
- Generally, please try to any platform-specific code in NWNXLib contained within the Platform namespace.

API generation:

Step 1: Compile nwserver
Step 2: Open nwserver in IDA, file -> script file -> dumpFunctions.idc
Step 3: D:\log.txt -> F:\NWN\git\symbol_parser\Data\rawdumplinuxserver
Step 4 (optional): Repeat above for windows server, outputting to F:\NWN\git\symbol_parser\Data\rawdumpwindows
Step 5: IDA -> File -> Produce File -> Export C header -> untick generate compilable and include ida basic types -> <folder>\structs
Step 6: Invoke cleanstructfile with "F:\NWN\git\symbol_parser\Data\structs" "F:\NWN\git\symbol_parser\Data\formattedstructs"
Step 7: Open formattedstructs, find CResRef, change RESREF to char[16], e.g. char m_resRef[16];.
Step 8: Invoke symbolparser with -parse="F:\NWN\git\symbol_parser\Data\rawdumplinuxserver" -crossref="F:\NWN\git\symbol_parser\code\Data\rawdumpwindowsserver" -structs="F:\NWN\git\symbol_parser\Data\formattedstructs" -outdir="F:\NWN\git\symbol_parser\Out" -classListPath="F:\NWN\git\symbol_parser\Data\desiredstructs"
Step 9: Transfer desiredstructs to linux and edit as required
Step 10: gdb nwserver (the exe we opened in IDA earlier)
Step 11: source /nwnx/symbol_parser/Scripts/gdbsizes.py after editing the paths in the script
Step 12: Transfer the output file back to Windows
Step 13: Invoke symbolparser with same as before, plus -assertOnSizePath="F:\NWN\git\symbol_parser\Data\knownstructsizes"
Step 14: API complete!
