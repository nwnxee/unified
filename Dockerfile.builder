FROM i386/debian:stretch-slim
LABEL maintainer "niv@nwnx.io"

RUN apt-get update

# core stuff
RUN apt-get install -y --no-install-recommends  \
  build-essential cmake gperf git \
  gcc-6 g++-6

# NWNX_SQL
RUN apt-get install -y default-libmysqlclient-dev libpq-dev libsqlite3-dev

# NWNX_SECCOMP
RUN apt-get install -y libseccomp-dev

# NWNX_RUBY
RUN apt-get install -y ruby-dev

# NWNX_JVM
RUN mkdir -p /usr/share/man/man1
RUN apt-get install -y openjdk-8-jdk-headless
RUN apt-get install -y ant

# NWNX_LUA
RUN apt-get install -y libluajit-5.1-dev

# slim down the image again.
RUN rm -r /var/lib/apt/lists /var/cache/apt
