# -*- mode: ruby -*-
# vi: set ft=ruby :
# Install vagrant-disksize to allow resizing the vagrant box disk.
unless Vagrant.has_plugin?("vagrant-disksize")
  raise  Vagrant::Errors::VagrantError.new, "vagrant-disksize plugin is missing. Please install it using 'vagrant plugin install vagrant-disksize' and rerun 'vagrant up'"
end
Vagrant.configure("2") do |config|
    config.disksize.size = '15GB'

    config.vm.provider :hyperv do |v|
      v.maxmemory = 4096
      v.memory = 4096
      v.cpus = 4
      config.vm.synced_folder ".", "/vagrant", create: true, disabled: false
    end
    config.vm.provider :libvirt do |v|
        v.memory = 4096
        v.cpus = 8
        v.qemu_use_session = false
#       v.memorybacking :access, :mode => "shared"
#        config.vm.synced_folder "./", "/vagrant", type: "virtiofs"
    end  
  
    config.vm.provision :shell, privileged: true, inline: $install_common_tools
  
    config.vm.define :main, primary: true do |main|
      main.vm.box = "generic/ubuntu2004"
      main.vm.hostname = "main"
      main.vm.network :private_network, ip: "10.0.0.10"
      main.vm.provision :shell, privileged: false, inline: $run_target, args: "10.0.0.10"
    end
  
  end
  
  $install_common_tools = <<-SCRIPT
  # install dependencies
  echo "installing global dependencies"
  export DEBIAN_FRONTEND=noninteractive
  apt-get -qq update
  apt-get -qq install make build-essential unzip tar python3 python3-pip docker.io
  wget https://www.nordicsemi.com/-/media/Software-and-other-downloads/Desktop-software/nRF-command-line-tools/sw/Versions-10-x-x/10-15-0/nrf-command-line-tools-10.15.0_amd.zip
  unzip nrf-command-line-tools-10.15.0_amd.zip -d /tmp/ && rm nrf-command-line-tools-10.15.0_amd.zip
  wget "https://www.nordicsemi.com/-/media/Software-and-other-downloads/SDKs/nRF5/Binaries/nRF5SDK153059ac345.zip"
  unzip nRF5SDK153059ac345.zip
  rm nRF5SDK153059ac345.zip
  tar -C /usr/local/ -xvf /tmp/nrf-command-line-tools-10.15.0_Linux-amd64.tar.gz
  ln -s /usr/local/nrf-command-line-tools/bin/mergehex /usr/bin/mergehex
  wget https://developer.nordicsemi.com/nRF5_SDK/nRF5_SDK_v15.x.x/nRF5_SDK_15.3.0_59ac345.zip
  unzip nRF5_SDK_15.3.0_59ac345.zip -d /vagrant/ && rm nRF5_SDK_15.3.0_59ac345.zip
  wget -O gcc-arm.tar.bz2 https://developer.arm.com/-/media/Files/downloads/gnu-rm/7-2018q2/gcc-arm-none-eabi-7-2018-q2-update-linux.tar.bz2
  tar -xvf gcc-arm.tar.bz2 -C /usr/local/ 
  rm gcc-arm.tar.bz2
  pip3 install nrfutil
  ls -la /usr/local
  usermod -aG docker vagrant
  chown -R vagrant:vagrant .
  SCRIPT
  
  $run_target = <<-SHELL
  cd /vagrant
  export DATE=$(date +"%Y%m%d_%H%M%S")
  echo '#define BUILDNUMBER "Build '$DATE'"' > src/buildnum.h
  # make -j $(nproc --all) ruuvitag_b
  SHELL
