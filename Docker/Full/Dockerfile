FROM alpine/git as git
WORKDIR /tmp
RUN git clone https://github.com/nwnxee/unified

FROM nwnxee/builder as builder
WORKDIR /nwnx/home
COPY --from=git /tmp/unified/ .
# Compile nwnx
RUN Scripts/buildnwnx.sh -j $(nproc)

FROM beamdog/nwserver
RUN mkdir /nwn/nwnx
COPY --from=builder /nwnx/home/Binaries/* /nwn/nwnx/
# Install mono
ENV MONO_VERSION 5.10.0.160
RUN apt-get update \
    && apt-get -y install gnupg2 \
    && apt-key adv --keyserver hkp://keyserver.ubuntu.com:80 --recv-keys 3FA7E0328081BFF6A14DA29AA6A19B38D3D831EF \
    && apt-get -y install apt-transport-https \
    && echo "deb http://download.mono-project.com/repo/debian stable-stretch/snapshots/$MONO_VERSION main" > /etc/apt/sources.list.d/mono-official-stable.list \
    && apt-get update \
    && apt-get install -y mono-runtime binutils curl mono-devel ca-certificates-mono fsharp mono-vbnc nuget referenceassemblies-pcl \
    && rm -rf /var/cache/apt /var/lib/apt/lists /tmp/*
# Create man directive so update-alternatives can successfully configure java
RUN mkdir -p /usr/share/man/man1
# Install plugin run dependencies
RUN runDeps="hunspell \
    openjdk-8-jdk-headless \
    libmariadbclient18 \
    libpq-dev \
    libruby2.3 \
    luajit libluajit-5.1 \
    libssl1.1" \
    && apt-get update \
    && apt-get -y install --no-install-recommends $runDeps \
    && rm -r /var/cache/apt /var/lib/apt/lists
# Configure nwserver to run with nwnx
ENV NWNX_CORE_LOAD_PATH=/nwn/nwnx/
ENV NWN_LD_PRELOAD="/nwn/nwnx/NWNX_Core.so"
# Use NWNX_ServerLogRedirector as default log manager
ENV NWNX_SERVERLOGREDIRECTOR_SKIP=n \
    NWN_TAIL_LOGS=n \
    NWNX_CORE_LOG_LEVEL=7 \
    NWNX_SERVERLOGREDIRECTOR_LOG_LEVEL=6
# Configure JVM
ENV NWNX_JVM_CLASSPATH=/nwn/nwnx/org.nwnx.nwnx2.jvm.jar
# Disable all other plugins by default. Remember to add new plugins to this list.
ENV NWNX_ADMINISTRATION_SKIP=y \
    NWNX_BEHAVIOURTREE_SKIP=y \
    NWNX_CHAT_SKIP=y \
    NWNX_CREATURE_SKIP=y \
    NWNX_DAMAGE_SKIP=y \
    NWNX_DATA_SKIP=y \
    NWNX_EVENTS_SKIP=y \
    NWNX_ITEM_SKIP=y \
    NWNX_JVM_SKIP=y \
    NWNX_LUA_SKIP=y \
    NWNX_METRICS_INFLUXDB_SKIP=y \
    NWNX_MONO_SKIP=y \
    NWNX_OBJECT_SKIP=y \
    NWNX_PLAYER_SKIP=y \
    NWNX_PROFILER_SKIP=y \
    NWNX_SPELLCHECKER_SKIP=y \
    NWNX_REDIS_SKIP=y \
    NWNX_RUBY_SKIP=y \
    NWNX_SQL_SKIP=y \
    NWNX_THREADWATCHDOG_SKIP=y \
    NWNX_TIME_SKIP=y \
    NWNX_TRACKING_SKIP=y \
    NWNX_TWEAKS_SKIP=y \
    NWNX_WEAPON_SKIP=y \
    NWNX_WEBHOOK_SKIP=y
