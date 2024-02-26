# This image serves as the factory for compiling the sources, and must be updated whenever the
# build dependencies change. This docker image created is pushed to Dockerhub and GHCR and is the base
# image when users build their own docker images for NWNX:EE.

FROM debian:buster-slim

RUN buildDeps="build-essential \
    git \
    ssh-client \
    zip \
    cmake \
    gperf \
    gcc-7 \
    g++-7 \
    default-libmysqlclient-dev \
    libpq-dev \
    libseccomp-dev \
    ruby-dev \
    libssl-dev \
    libhunspell-dev \
    pkg-config \
    libluajit-5.1-dev \
    libpcre3 \
    libpcre3-dev \
    autoconf \
    automake \
    bison \
    ccache" \
    && apt-get update \
    && apt-get install -y --no-install-recommends $buildDeps \
    && apt-get clean \
    && rm -r /var/lib/apt/lists /var/cache/apt \
    && git clone --branch v4.0.2 --depth 1 https://github.com/swig/swig.git \
    && cd swig \
    && ./autogen.sh \
    && ./configure \
    && make \
    && make install
