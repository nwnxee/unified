FROM debian:stretch-slim
LABEL maintainer "niv@nwnx.io"

RUN dpkg --add-architecture i386 && apt-get update

# core stuff
RUN apt-get install -y --no-install-recommends  \
  build-essential cmake gperf git \
  gcc-6-multilib g++-6-multilib

# NWNX_SQL
RUN apt-get install -y default-libmysqlclient-dev:i386

# NWNX_SECCOMP
RUN apt-get install -y libseccomp-dev:i386

# slim down the image again.
RUN rm -r /var/lib/apt/lists /var/cache/apt

CMD ["/bin/bash"]
