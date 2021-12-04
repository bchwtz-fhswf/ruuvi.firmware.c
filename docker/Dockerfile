FROM archlinux:latest

WORKDIR /work

RUN pacman --noconfirm -Sy unzip base-devel wget tar fish python python-pip git
RUN wget https://www.nordicsemi.com/-/media/Software-and-other-downloads/Desktop-software/nRF-command-line-tools/sw/Versions-10-x-x/10-15-0/nrf-command-line-tools-10.15.0_amd.zip
RUN unzip nrf-command-line-tools-10.15.0_amd.zip -d /tmp/ && rm nrf-command-line-tools-10.15.0_amd.zip
RUN mkdir /tools
WORKDIR /tools
RUN wget "https://www.nordicsemi.com/-/media/Software-and-other-downloads/SDKs/nRF5/Binaries/nRF5SDK153059ac345.zip"
RUN unzip nRF5SDK153059ac345.zip 
RUN rm nRF5SDK153059ac345.zip
WORKDIR /work
RUN tar -C /usr/local/ -xvf /tmp/nrf-command-line-tools-10.15.0_Linux-amd64.tar.gz
RUN ln -s /usr/local/nrf-command-line-tools/bin/mergehex /usr/bin/mergehex
RUN wget https://developer.nordicsemi.com/nRF5_SDK/nRF5_SDK_v15.x.x/nRF5_SDK_15.3.0_59ac345.zip
RUN unzip nRF5_SDK_15.3.0_59ac345.zip && rm nRF5_SDK_15.3.0_59ac345.zip
RUN wget -O gcc-arm.tar.bz2 https://developer.arm.com/-/media/Files/downloads/gnu-rm/7-2018q2/gcc-arm-none-eabi-7-2018-q2-update-linux.tar.bz2
RUN tar -xvf gcc-arm.tar.bz2 -C /usr/local/ 
RUN pip install nrfutil
RUN ls -la /usr/local

# ADD . .

# WORKDIR /work/src

# RUN make ruuvitag_b
