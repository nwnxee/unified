# This image is created after a Github Actions build and should only be used then. We use the artifacts from
# that build instead of rebuilding from source again then push our image to Dockerhub and GHCR.

ARG NWNXEE_BASE_IMAGE=nwnxee/nwnxee-base
FROM $NWNXEE_BASE_IMAGE
RUN mkdir -p /nwn/nwnx
ADD ./NWNX-EE.tar /nwn/nwnx

# Configure nwserver to run with nwnx
ENV NWNX_CORE_LOAD_PATH=/nwn/nwnx/
ENV NWN_LD_PRELOAD="/nwn/nwnx/NWNX_Core.so"
# Use NWNX_ServerLogRedirector as default log manager
ENV NWNX_SERVERLOGREDIRECTOR_SKIP=n \
    NWN_TAIL_LOGS=n \
    NWNX_CORE_LOG_LEVEL=6 \
    NWNX_SERVERLOGREDIRECTOR_LOG_LEVEL=6
# Disable all other plugins by default.
ENV NWNX_CORE_SKIP_ALL=y
