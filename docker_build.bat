docker run -v %cd%:/work sysexect/ruuvi-build-env:latest fish --command="mv -n /tools/nRF5_SDK_15.3.0_59ac345 /tmp/nRF5_SDK_15.3.0_59ac345 && echo '#define BUILDNUMBER \"Build '(date +\"%Y%m%d_%H%M%S\")'\"' > src/buildnum.h && rsync --recursive -v --update * /tmp && cd /tmp && cd src && make -j (nproc --all) ruuvitag_b && rsync -v --recursive targets/ruuvitag_b/armgcc/* /work/src/targets/ruuvitag_b/armgcc/"
