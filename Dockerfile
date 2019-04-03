FROM nwnxee/builder as builder
WORKDIR /nwnx/home
COPY ./ .
# Compile nwnx
RUN Scripts/buildnwnx.sh -j $(nproc)

FROM beamdog/nwserver
RUN mkdir /nwn/nwnx
COPY --from=builder /nwnx/home/Binaries/* /nwn/nwnx/

# Copy our modified run-server.sh
COPY --from=builder /nwnx/home/Scripts/Docker/run-server.sh /nwn/
RUN chmod +x /nwn/run-server.sh

# Install plugin run dependencies
RUN runDeps="hunspell \
    libmariadbclient18 \
    libpq-dev \
    libsqlite3-dev \
    libruby2.3 \
    luajit libluajit-5.1 \
    libssl1.1 \
    inotify-tools" \
    && apt-get update \
    && apt-get -y install --no-install-recommends $runDeps \
    && rm -r /var/cache/apt /var/lib/apt/lists
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
