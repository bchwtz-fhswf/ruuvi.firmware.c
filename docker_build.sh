#!/bin/bash
DATE=$(date +"%Y%m%d_%H%M%S")
echo '#define BUILDNUMBER "Build '$DATE'"' > src/buildnum.h
docker run -v $(pwd):/work sysexect/ruuvi-build-env:latest fish --command='cd src && make -j (nproc --all) ruuvitag_b'