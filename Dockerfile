FROM jakkn/unified:builder as builder
WORKDIR /nwnx
COPY ./ .
WORKDIR /nwnx/build
# compile nwnx
RUN CC="gcc -m32" CXX="g++ -m32" cmake .. && make

FROM beamdog/nwserver:latest
COPY --from=builder /nwnx/Binaries/NWNX_Core.so /nwn/data/bin/linux-x86/
# Configure nwserver to run with nwnx 
ENV NWN_LD_PRELOAD="./NWNX_Core.so"
