ARG IMAGE
ARG TAG
FROM $IMAGE:$TAG

# Create man directive so update-alternatives can successfully configure java
RUN mkdir -p /usr/share/man/man1

# Install deps
ENV MONO_VERSION 5.16.0.220
ENV APT_KEY_DONT_WARN_ON_DANGEROUS_USAGE=1
RUN javaDeps="openjdk-8-jdk-headless" \
    monoDeps="mono-runtime binutils curl mono-devel ca-certificates-mono fsharp mono-vbnc nuget referenceassemblies-pcl" \
    && apt-get update \
    && apt-get -y install gnupg2 \
    && apt-key adv --no-tty --keyserver hkp://keyserver.ubuntu.com:80 --recv-keys 3FA7E0328081BFF6A14DA29AA6A19B38D3D831EF \
    && apt-get -y install apt-transport-https \
    && echo "deb http://download.mono-project.com/repo/debian stable-stretch/snapshots/$MONO_VERSION main" > /etc/apt/sources.list.d/mono-official-stable.list \
    && apt-get update \
    && apt-get install -y --no-install-recommends $javaDeps \
    && apt-get install -y $monoDeps \
    && rm -rf /var/cache/apt /var/lib/apt/lists /tmp/*

# Configure JVM
ENV NWNX_JVM_CLASSPATH=/nwn/nwnx/org.nwnx.nwnx2.jvm.jar
