[![Discord](https://img.shields.io/discord/382306806866771978.svg?colorB=7289DA&label=Discord&logo=Discord&logoColor=7289DA&style=flat-square)](https://discord.gg/hxTt8Fr)

# NWNX:EE (build 8193.37.15 - v89)

- Latest release: [build8193.37.13-HEAD](https://github.com/nwnxee/unified/releases/latest) - [Changelog](https://github.com/nwnxee/unified/blob/master/CHANGELOG.md#Unreleased)
- Docker tag: `nwnxee/unified:latest`
- nwserver-linux md5: `745847640ed0821ca087f86c92bdef74`

@mainpage
@tableofcontents

## What is NWNX:EE?

NWNX:EE stands for Neverwinter Nights Extender: Enhanced Edition. In a nutshell, NWNX:EE is a framework that developers can use to modify existing hardcoded rules or inject brand new functionality into Neverwinter Nights: Enhanced edition.

Using NWNX:EE, developers can make plugins to do anything they want, including but not limited to:

1.  Create brand new scripting commands as if they were part of the base game's scripting API.
2.  Integrate the game's scripting language with external tools, processes, and databases, such as MySQL.
3.  Modify existing mechanics that are conventionally difficult or impossible to change, such as the core combat rules or the path finding engine.

NWNX:EE is not just for plugin developers. Module creators can use plugins created by the NWNX:EE contributors to expand the scripting and systems functionality of their modules.

Check out the [Awesome NWNX page](Awesome-NWNX.md) for a list projects using NWNX.

## What versions of the server are supported?

The most recent build of NWN:EE that is supported can be discovered at the top of this file. Please note that we do NOT support any server binaries other than the one in the dedicated server package. We support neither the binary released through the Beamdog client nor the one released through the Steam client. That said, the Steam and Beamdog binaries are almost always identical to the one in the dedicated server package, see the top of this readme for a md5sum of the binary we support.

The dedicated server packages can be found here: https://nwn.beamdog.net/downloads/

## What platforms are supported?

Only Linux is natively supported. It is possible to run NWNX:EE on Windows using Docker to emulate a Linux server environment or WSL/WSL2 when using Windows 10. At this point in time there are no plans for native Windows support of NWNX:EE.

## How do I use it?

First of all, you need to get the NWNX binaries. If you want to compile the binaries yourself, refer to the compiling section below. Otherwise, you can download the binaries by clicking on the [Releases](https://github.com/nwnxee/unified/releases) header to the right of the GitHub repository page.

## Integrating NWNX:EE into your module

Each NWNX:EE [Release](https://github.com/nwnxee/unified/releases) has a `NWScript.zip` file containing all of the scripts files, if you have built NWNX:EE yourself the `NWScript.zip` file will be in your `Binaries` folder. Simply import the scripts into your module and call the functions as you would any other scripting function. Be sure to update these scripts whenever updating NWNX, and then rebuild all your scripts in your module.

## Running the server (native)

Given the binaries, follow these steps:

1.  Copy the binaries next to the server executable. This will usually be in /bin/linux-x86.
2.  Create a startup script that looks like this:

        #!/bin/sh
        export LD_PRELOAD="./NWNX_Core.so"
        ./nwserver-linux

3.  You can optionally configure plugins using environment variables. At the moment you will need to search the plugin documentation to find the correct environment variables: each plugin, located in the Plugins/ folder in the source tree, has a README.md which contains some information about the plugin.

4.  You can skip a particular plugin by adding a line that looks like this before starting nwserver-linux:

        export NWNX_LUA_SKIP=true

5.  You can set the log levels like this, which governs the verbosity of log output, with 1 being the least verbose and 7 being the most verbose.

        export NWNX_CORE_LOG_LEVEL=7 # Default log level for core and all plugins
        export NWNX_LUA_LOG_LEVEL=7 # Log level for LUA, overrides default

Optionally, you can use Docker to run the server with pre-built NWNX binaries. Refer to the section below

## Running the server (Docker)

`nwnxee/unified` supports the following [tags](https://hub.docker.com/r/nwnxee/unified/tags):

* `[commit-hash]` (7 characters)
* `latest`
* `[tag]` (for example: `build8193.20` or `build8193.35.36`)

Due to Docker's local image cache we recommend using the `[commit-hash]` tag to explicitly state which nwnx build to run. In comparison, the `latest` tag will usually hit the image cache and return an outdated build, as you have to run `docker pull nwnxee/unified` to update the `latest` image in your cache. Using the `[commit-hash]` tag removes the need to manually run docker pull on your machines, and enables you to roll back in a simple and sensible manner.

Run the image exactly the same as you would run the `urothis/nwserver` image. For any questions related to running nwserver, please refer to the nwserver [README](https://hub.docker.com/r/urothis/nwserver/).

nwnxee plugins are configured using environment variables passed to `docker run`. With the exception of ServerLogRedirector, all plugins are skipped by default. Plugins are activated by passing `n` to the corresponding environment variable for a given plugin in order to not skip it, e.g. `-e NWNX_ADMINISTRATION_SKIP=n`.

Some plugins require additional configurations, like for instance the database plugin. To find plugin specific configurations please refer to the README of the given plugin located in its directory.

It is advised to configure the container with docker-compose. Please refer to these resources for documentation and examples

* https://docs.docker.com/compose/
* Example compose file: [nwnxee-template](https://github.com/Urothis/nwnxee-template/blob/master/docker-compose.yml)

## Running the server (Windows 10 WSL1)

As of NWN:EE Release 8193 it is possible to run `nwserver-linux` and NWNX:EE on Windows 10's Subsystem for Linux. See this guide on how to do so: [NWNX:EE on WSL1, a brief guide](https://github.com/Daztek/NWNX-WSL)

## Compiling NWNX:EE (native)

Please note that you need a modern C++17 compatible compiler to build NWNX:EE. The code is confirmed to build on GCC 7.4+, Clang 5.0+ might work but is not supported. It may be possible to build on an older compiler.

Each plugin may have one or more dependencies that must be satisfied in order to build that plugin. Refer to each individual plugin's CMakeLists.txt to determine their dependencies.

To build the typical way:

- Execute: `./Scripts/buildnwnx.sh`

Or, if you want to compile manually:

- Execute: `mkdir build-nwnx && cd build-nwnx && cmake .. && make`

## Compiling NWNX:EE (docker)

To build on Linux, MacOS, or Docker-Toolbox:

1.  Execute ./Scripts/rundockerbuild.sh
2.  The script will pull the NWNX Linux Docker builder image
3.  The Container will execute the ./scripts/buildnwnx.sh script
4.  To perform a clean build pass -c eg './scripts/rundockerbuild.sh -c'
5.  To perform multi-threaded compilation pass -j.

To build on Windows:

1.  Execute ./Scripts/rundockerbuild.ps1
2.  The script will pull the NWNX Linux Docker builder image
3.  The Container will execute the ./scripts/buildnwnx.sh script
4.  To perform a clean build pass -FORCECLEAN eg './scripts/rundockerbuild.ps1 -FORCECLEAN'

## Docker images

Prebuilt images exist for the master branch and can be found under [nwnxee/package](https://github.com/orgs/nwnxee/packages?repo_name=unified). The Dockerfiles in this repository serve the following purposes:

1. `builder.Dockerfile` defines the environment to compile nwnx ([ghcr.io/nwnxee/builder](https://github.com/nwnxee/unified/pkgs/container/builder))
1. `base.Dockerfile` defines the environment to run nwserver and nwnx, but has no nwnx binaries ([ghcr.io/nwnxee/nwnxee-base](https://github.com/nwnxee/unified/pkgs/container/nwnxee-base))
1. `gha.Dockerfile` defines the environment to run nwserver and nwnx, using binaries built by CI [ghcr.io/nwnxee/unified](https://github.com/nwnxee/unified/pkgs/container/unified)
1. `Dockerfile` defines the environment to run nwserver and nwnx, using binaries built locally with the builder image, and based on the local base image

Note that the nwserver binary in the base image is included by starting "FROM [ghcr.io/urothis/nwserver](https://github.com/urothis/nwserver/pkgs/container/nwserver)".

It is recommended to use the prebuilt images for production environments. If you cannot use a prebuilt image (e.g. if you are testing a preview branch), you can build the image locally using `Dockerfile`. You may use `Scripts/buildimages.sh` to do this, or run the docker build commands yourself.

## Contributing code

All contribution are welcome. See [CONTRIBUTING.md](CONTRIBUTING.md) for requirements and style guidelines.

## Reporting bugs

Use the [issue tracker](https://github.com/nwnxee/unified/issues/new) to report any bugs. Please always provide the relevant `stdout` output of your runs, ideally at debug log level (`NWNX_CORE_LOG_LEVEL=7`).

## Who makes NWNX:EE?

The project is an open source project created and maintained by community members for free in their spare time.

## You're awesome, let me pay you

Thanks, but you should donate your dolla dolla bills to a good cause instead. If you really want to spend money to support NWN, consider donating to [Neverwinter Vault](https://neverwintervault.org/) to cover their server hosting costs.

## Contact

The team can be contacted on Discord using the invite at the following URL: https://discord.gg/hxTt8Fr
