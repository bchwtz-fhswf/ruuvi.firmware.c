#!/bin/bash
docker run -v $(pwd):/work sysexect/ruuvi-build-env:latest fish --command='cd src && make ruuvitag_b'