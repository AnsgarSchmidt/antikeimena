FROM ubuntu:17.10
RUN apt-get update && apt-get upgrade -y
RUN apt-get install -y autoconf automake libtool curl \
                       make g++ unzip mc git vim \
                       python python-pip python-protobuf
RUN git clone https://github.com/google/protobuf.git
WORKDIR protobuf
RUN ./autogen.sh
RUN ./configure
RUN make
RUN make check
RUN make install
RUN ldconfig

WORKDIR /
RUN git clone https://github.com/nanopb/nanopb.git
WORKDIR /nanopb/generator/proto
RUN make

WORKDIR /
