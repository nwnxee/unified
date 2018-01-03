<#
.SYNOPSIS
    Execute a Docker build for the NWNX code
.DESCRIPTION
    Pulls the NWNX Docker build Image and runs a container to execute local builds of NWNX Linux.  Removes the requirement to confiure a local buil environment as the Docker image is preconfigured.
#>
Param(
    # Clean build - remove Binaries and re-execute cmake
    [switch]$FORCECLEAN = $false
)

if ($FORCECLEAN) {
    $CLEAN = "-c"
}

docker run --rm -w /nwnx/home --entrypoint "/bin/bash" -v ${PWD}:/nwnx/home docker.nwnx.io:443/nwnxee/unified:builder /nwnx/home/scripts/buildnwnx.sh $CLEAN