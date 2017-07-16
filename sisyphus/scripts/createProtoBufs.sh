#!/usr/bin/env bash

for name in status
do
    protoc --proto_path ../../protobuf/ --python_out=../python ../../protobuf/${name}.proto
    protoc --proto_path ../../protobuf/ -o ${name}.pb          ../../protobuf/${name}.proto
    python /nanopb/generator/nanopb_generator.py ${name}.pb
    rm ${name}.pb
    mv ${name}.pb.c ../../arduino/src/main/
    mv ${name}.pb.h ../../arduino/src/main/
done

cp /nanopb/pb.h ../../arduino/src/main/
cp /nanopb/pb_common.h ../../arduino/src/main/
cp /nanopb/pb_common.c ../../arduino/src/main/
cp /nanopb/pb_decode.h ../../arduino/src/main/
cp /nanopb/pb_decode.c ../../arduino/src/main/
cp /nanopb/pb_encode.h ../../arduino/src/main/
cp /nanopb/pb_encode.c ../../arduino/src/main/

