# This image serves as the factory for compiling the sources, and must be updated whenever the
# build dependencies change. This docker image created is pushed to Dockerhub and GHCR and is the base
# image when users build their own docker images for NWNX:EE.

FROM debian:bookworm-slim

RUN buildDeps="build-essential \
    git \
    ssh-client \
    zip \
    cmake \
    gperf \
    gcc \
    g++ \
    swig \
    default-libmysqlclient-dev \
    libpq-dev \
    libseccomp-dev \
    ruby-dev \
    libssl-dev \
    pkg-config \
    libpcre3 \
    libpcre3-dev \
    autoconf \
    automake \
    bison \
    ccache" \
    && apt-get update \
    && apt-get install -y --no-install-recommends $buildDeps \
    && apt-get clean \
    && rm -r /var/lib/apt/lists /var/cache/apt

