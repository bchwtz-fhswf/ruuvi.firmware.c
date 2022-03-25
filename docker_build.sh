#!/bin/bash
DATE=$(date +"%Y%m%d_%H%M%S")
echo '#define BUILDNUMBER "Build '$DATE'"' > src/buildnum.h
docker run -it -v "$(pwd)":/work sysexect/ruuvi-build-env:latest fish --command='mv -n /tools/nRF5_SDK_15.3.0_59ac345 /work/nRF5_SDK_15.3.0_59ac345 && cd src && make -j (nproc --all) ruuvitag_b'
