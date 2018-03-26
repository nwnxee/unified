# NWNX:EE (build 8166)

## What is NWNX:EE?

NWNX:EE stands for Neverwinter Nights Extender: Enhanced Edition. In a nutshell, NWNX:EE is a framework that developers can use to modify existing hardcoded rules or inject brand new functionality into Neverwinter Nights: Enhanced edition.

Using NWNX:EE, developers can make plugins to do anything they want, including but not limited to:

1. Create brand new scripting commands as if they were part of the base game's scripting API.
2. Integrate the game's scripting language with external tools, processes, and databases, such as MySQL.
3. Modify existing mechanics that are conventionally difficult or impossible to change, such as the core combat rules or the path finding engine.

NWNX:EE is not just for plugin developers. Module creators can use plugins created by the NWNX:EE contributors to expand the scripting and systems functionality of their modules.

## What versions of the server are supported?

The most recent build of NWN:EE that is supported can be discovered at the top of this file. Please note that we do NOT support any server binaries other than the one in the dedicated server package. We support neither the binary released through the Beamdog client nor the one released through the Steam client. We release an update for each new version of the dedicated server package, which can be found here: https://forums.beamdog.com/discussion/67157/server-download-packages-and-docker-support/p1

## What platforms are supported?

Only Linux is currently supported. It is possible to run NWNX:EE on Windows using Docker to emulate a Linux server environment. Refer to the sections below to find out how. There are plans to bring native Windows support to NWNX:EE but these plans currently lack a concrete schedule.

## How do I use it?

First of all, you need to get the NWNX binaries. If you want to compile the binaries yourself, refer to the compiling section below. Otherwise, you can download the binaries by clicking on the CircleCI link at the top of the GitHub repository page, log in, then navigate to the build list and choose artifacts.

## Integrating NWNX:EE into your module

The built binaries (when built using the build script or downloaded as artifacts) will contain a folder in which all of the script files associated with NWNX:EE live. Simply import these into your module and call the functions as you would any other scripting function. Some may not compile with the default compiler - it is safe to delete these scripts if you do not need to use the associated plugins.

## Running the server (native)

Given the binaries, follow these steps:

1. Copy the binaries next to the server executable. This will usually be in /bin/linux-x86.
2. Create a startup script that looks like this:

        #!/bin/sh
        export LD_PRELOAD="./NWNX_Core.so"
        ./nwserver-linux

3. You can optionally configure plugins using environment variables. At the moment you will need to search the plugin documentation to find the correct environment variables: each plugin, located in the Plugins/ folder in the source tree, has a Documentation folder which contains some information about the plugin. Please note that not all environment variables will be documented so you may need to dig through the source code.

4. You can skip a particular plugin by adding a line that looks like this before starting nwserver-linux:
        
        export NWNX_JVM_SKIP=true

5. You can set the log levels like this, which governs the verbosity of log output, with 1 being the least verbose and 7 being the most verbose.

        export NWNX_CORE_LOG_LEVEL=7 # Default log level for core and all plugins
        export NWNX_JVM_LOG_LEVEL=7 # Log level for JVM, overrides default

Optionally, you can use Docker to run the server with pre-built NWNX binaries. Refer to the section below 

## Running the server (Docker)

[TODO] Glorwinger, fill me in.

## Compiling NWNX:EE (native)

Please note that you need a modern C++ compiler to build NWNX:EE. The code is confirmed to build on GCC 6.4 + or Clang 4.0 +. It may be possible to build on an older compiler.

Each plugin may have one or more dependencies that must be satisfied in order to build that plugin. Refer to each individual plugin's CMakeLists.txt to determine their dependencies.

To build the typical way:

1. Execute ./Scripts/buildnwnx.sh

Or, if you want to compile manually:

1. Execute CC=gcc -m32 CXX=g++ -m32 mkdir build && cd build && cmake .. && make

## Compiling NWNX:EE (docker)

To build on Linux, MacOS, or Docker-Toolbox:

1. Execute ./Scripts/rundockerbuild.sh
2. The script will pull the NWNX Linux Docker builder image
3. The Container will execute the ./scripts/buildnwnx.sh script
4. To perform a clean build pass -c eg './scripts/rundockerbuild.sh -c'
5. To perform multi-threaded compilation pass -j.

To build on Windows:

1. Execute ./Scripts/rundockerbuild.ps1
2. The script will pull the NWNX Linux Docker builder image
3. The Container will execute the ./scripts/buildnwnx.sh script
4. To perform a clean and build pass -FORCECLEAN eg './scripts/rundockerbuild.ps1 -FORCECLEAN'

## Contributing code

All contribution are welcome. The only requirement is that the code you contribute adheres to the following restrictions:

1. Prefix members variables with m_.
2. Use lowerCamelCase for variables.
3. Use UpperCamelCase for functions.
4. Use UpperCamelCase for classes.
5. Use ALL_CAPS for constants and macros.
6. Braces always start on a new line and always end on a new line.
7. Spaces, not tabs.
8. Avoid manual memory management. Use unique_ptr always. This helps transparent hotloading later!

Most importantly, be sure never to manually write memory addresses or hooks yourself. These must ALWAYS go through the core systems to make sure that plugins can play nicely together.

## Who makes NWNX:EE?

The project is an open source project created and maintained by community members for free in their spare time.

## You're awesome, let me pay you

Thanks, but you should donate your dolla dolla bills to a good cause instead. If you really want to spend money to support NWN, consider donating to Neverwinter Vault to cover their sever hosting costs.

## Contact

The team can be contacted on Discord using the invite at the following URL: https://discord.gg/hxTt8Fr
