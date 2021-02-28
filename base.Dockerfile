# This image is the base for NWNX:EE, it includes all the dependencies required to run NWNX and all plugins. It
# is used as an intermediary image before the freshly built binaries are dropped in.

ARG BD_NWSERVER_IMAGE=beamdog/nwserver
FROM $BD_NWSERVER_IMAGE
RUN mkdir -p /nwn/nwnx

# Install plugin run dependencies
RUN runDeps="hunspell \
    default-libmysqlclient-dev \
    libmariadb3 \
    libpq5 \
    libsqlite3-0 \
    libruby2.5 \
    luajit libluajit-5.1 \
    libssl1.1 \
    inotify-tools \
    patch \
    unzip \
    dotnet-runtime-5.0 \
    dotnet-apphost-pack-5.0" \
    installDeps="ca-certificates wget" \
    && apt-get update \
    && apt-get install -y --no-install-recommends $installDeps \
    && wget https://packages.microsoft.com/config/debian/10/packages-microsoft-prod.deb -O packages-microsoft-prod.deb \
    && dpkg -i packages-microsoft-prod.deb \
    && apt-get update \
    && apt-get -y install --no-install-recommends $runDeps \
    && ln -s /usr/lib/x86_64-linux-gnu/libhunspell-?.*.so /usr/lib/x86_64-linux-gnu/libhunspell.so \
    && rm -rf /var/cache/apt /var/lib/apt/lists/*

# Patch run-server.sh with our modifications
COPY ./Scripts/Docker/run-server.patch /nwn
RUN patch /nwn/run-server.sh < /nwn/run-server.patch
