#!/bin/bash
#
# This script will:
# 1. Read the target nwserver version of the branch
# 2. Download the appropriate prebuilt nwserver image
# 3. Download the latest prebuilt builder image
# 4. Build the base image using (2)
# 5. Build nwnxee/unified image using (3) and (4)
#
GRAY='\e[90m'
NC='\033[0m'

set -e

pushd "$(git rev-parse --show-toplevel)" > /dev/null

nwn_build="$(grep 'set(TARGET_NWN_BUILD ' CMakeLists.txt | cut -d' ' -f2 | sed 's/)//')"
nwn_build_revision="$(grep 'set(TARGET_NWN_BUILD_REVISION ' CMakeLists.txt | cut -d' ' -f2 | sed 's/)//')"
nwn_build_postfix="$(grep 'set(TARGET_NWN_BUILD_POSTFIX ' CMakeLists.txt | cut -d' ' -f2 | sed 's/)//')"
nwn_version="$nwn_build.$nwn_build_revision.$nwn_build_postfix"

NWSERVER_IMAGE=ghcr.io/urothis/nwserver:"$nwn_version"
BUILDER_IMAGE=ghcr.io/nwnxee/builder
BASE_IMAGE=nwnxee/nwnxee-base:"$nwn_version"
NWNXEE_IMAGE=nwnxee/unified:"build$nwn_version-nwnx-$(git rev-parse --short HEAD)"

echo "Building images on branch '$(git rev-parse --abbrev-ref HEAD)'"
echo -e "  NWSERVER_IMAGE: $NWSERVER_IMAGE ${GRAY}(pull)${NC}"
echo -e "  BUILDER_IMAGE: $BUILDER_IMAGE ${GRAY}(pull)${NC}"
echo -e "  BASE_IMAGE: $BASE_IMAGE"
echo -e "  NWNXEE_IMAGE: $NWNXEE_IMAGE"
echo

# Pull recent images from the registry to avoid hitting local image cache
docker pull "$NWSERVER_IMAGE"
docker pull "$BUILDER_IMAGE"

docker build . \
  -f base.Dockerfile \
  -t "$BASE_IMAGE" \
  --build-arg NWSERVER_IMAGE="$NWSERVER_IMAGE"
docker build . \
  -t "$NWNXEE_IMAGE" \
  --build-arg BUILDER_IMAGE="$BUILDER_IMAGE" \
  --build-arg BASE_IMAGE="$BASE_IMAGE" \

popd > /dev/null

exit 0
