FROM archlinux:latest

WORKDIR /work

RUN pacman --noconfirm -Sy unzip base-devel wget tar fish python python-pip
RUN wget https://developer.nordicsemi.com/nRF5_SDK/nRF5_SDK_v15.x.x/nRF5_SDK_15.3.0_59ac345.zip
RUN unzip nRF5_SDK_15.3.0_59ac345.zip && rm nRF5_SDK_15.3.0_59ac345.zip
RUN wget -O gcc-arm.tar.bz2 https://developer.arm.com/-/media/Files/downloads/gnu-rm/7-2018q2/gcc-arm-none-eabi-7-2018-q2-update-linux.tar.bz2
RUN tar -xvf gcc-arm.tar.bz2 -C /usr/local/ 
RUN pip install nrfutil
RUN ls -la /usr/local

# ADD . .

# WORKDIR /work/src

# RUN make ruuvitag_b