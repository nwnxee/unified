# This image is for users who wish to build their images themselves. It uses the builder factory that is created
# via the builder.Dockerfile and the base that is created via the base.Dockerfile

ARG BUILDER_IMAGE
ARG BASE_IMAGE

FROM ${BUILDER_IMAGE:-nwnxee/builder} as builder
WORKDIR /nwnx/home
COPY ./ .
# Compile nwnx
ARG CC=gcc
ENV CC=$CC
ARG CXX=g++
ENV CXX=$CXX
RUN Scripts/buildnwnx.sh -j $(nproc)

FROM ${BASE_IMAGE:-nwnxee/nwnxee-base}
COPY --from=builder /nwnx/home/Binaries/* /nwn/nwnx/

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
