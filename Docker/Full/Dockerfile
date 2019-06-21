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
ENV MONO_VERSION 5.16.0.220
ENV APT_KEY_DONT_WARN_ON_DANGEROUS_USAGE=1
RUN apt-get update \
    && apt-get -y install gnupg2 \
    && apt-key adv --no-tty --keyserver hkp://keyserver.ubuntu.com:80 --recv-keys 3FA7E0328081BFF6A14DA29AA6A19B38D3D831EF \
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
    libsqlite3-dev \
    libruby2.3 \
    luajit libluajit-5.1 \
    libssl1.1 \
    inotify-tools \
    patch" \
    && apt-get update \
    && apt-get -y install --no-install-recommends $runDeps \
    && rm -r /var/cache/apt /var/lib/apt/lists

# Patch run-server.sh with our modifications
COPY --from=builder /nwnx/home/Scripts/Docker/run-server.patch /nwn/
RUN patch /nwn/run-server.sh < /nwn/run-server.patch

# Configure nwserver to run with nwnx
ENV NWNX_CORE_LOAD_PATH=/nwn/nwnx/
ENV NWN_LD_PRELOAD="/nwn/nwnx/NWNX_Core.so"
# Use NWNX_ServerLogRedirector as default log manager
ENV NWNX_SERVERLOGREDIRECTOR_SKIP=n \
    NWN_TAIL_LOGS=n \
    NWNX_CORE_LOG_LEVEL=6 \
    NWNX_SERVERLOGREDIRECTOR_LOG_LEVEL=6
# Configure JVM
ENV NWNX_JVM_CLASSPATH=/nwn/nwnx/org.nwnx.nwnx2.jvm.jar
# Disable all other plugins by default.
ENV NWNX_CORE_SKIP_ALL=y
