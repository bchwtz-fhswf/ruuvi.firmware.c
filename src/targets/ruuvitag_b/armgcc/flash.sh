#!/bin/bash
cd "$(dirname "$0")"
NAME="ruuvifw"
VERSION=$(git describe --exact-match --tags HEAD)
if [ -z "$VERSION" ]; then
  VERSION=$(git rev-parse --short HEAD)
fi

while getopts "n:v:" option;
do
case "${option}"
in
n) NAME=${OPTARG};;
v) VERSION=${OPTARG};;
esac
done
BINNAME=ruuvitag_b\_armgcc\_ruuvifw\_default\_${VERSION}

echo "nrfjprog --program ${BINNAME}_full.hex"

nrfjprog --eraseall
nrfjprog --program ${BINNAME}_full.hex
nrfjprog --reset
