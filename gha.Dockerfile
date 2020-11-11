# This image is created after a Github Actions build, we use the artifacts from
# that build instead of rebuilding from source again then push our image to Dockerhub and GHCR.

FROM beamdog/nwserver:8193.16
RUN mkdir -p /nwn/nwnx
COPY ./NWNX-EE.zip /nwn/nwnx

# Install plugin run dependencies
RUN runDeps="hunspell \
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
    && apt-get -y remove --purge ca-certificates wget \
    && apt-get -y autoremove \
    && rm -rf /var/cache/apt /var/lib/apt/lists/*

# Unzip the built binaries from Github Actions
RUN unzip /nwn/nwnx/NWNX-EE.zip -d /nwn/nwnx && rm /nwn/nwnx/NWNX-EE.zip

# Patch run-server.sh with our modifications
COPY ./Scripts/Docker/run-server.patch /nwn
RUN patch /nwn/run-server.sh < /nwn/run-server.patch

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
