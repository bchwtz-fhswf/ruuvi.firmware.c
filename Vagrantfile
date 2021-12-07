# -*- mode: ruby -*-
# vi: set ft=ruby :

Vagrant.configure("2") do |config|
    config.vm.provider :virtualbox do |v|
      v.memory = 2048
      v.cpus = 2
      config.vm.synced_folder ".", "/vagrant", create: true, disabled: false
    end
  
    config.vm.provision :shell, privileged: true, inline: $install_common_tools
  
    config.vm.define :main, primary: true do |main|
      main.vm.box = "generic/ubuntu2004"
      main.vm.hostname = "main"
      main.vm.network :private_network, ip: "10.0.0.10"
      main.vm.provision :shell, privileged: true, inline: $run_target, args: "10.0.0.10"
    end
  
  end
  
  $install_common_tools = <<-SCRIPT
  # bridged traffic to iptables is enabled for kube-router.
  cat >> /etc/ufw/sysctl.conf <<EOF
  net/bridge/bridge-nf-call-ip6tables = 1
  net/bridge/bridge-nf-call-iptables = 1
  net/bridge/bridge-nf-call-arptables = 1
  EOF
  
  # disable swap
  echo "disabling swap"
  swapoff -a
  sed -i '/swap/d' /etc/fstab
  
  # install dependencies
  echo "installing global dependencies"
  export DEBIAN_FRONTEND=noninteractive
  apt-get -qq update
  apt-get -qq install ebtables ethtool htop wget curl git net-tools tmux vim fish avahi-daemon libnss-mdns docker.io apt-transport-https inotify-tools
  
  # update docker config to use systemd cgroups
  echo "updating docker daemon configuration"
  cat >> /etc/docker/daemon.json <<EOF
  {
      "exec-opts": ["native.cgroupdriver=systemd"],
      "log-driver": "json-file",
      "log-opts": {
          "max-size": "100m"
      },
      "storage-driver": "overlay2"
  }
  EOF
  systemctl restart docker.service
  SCRIPT
  
  $run_target = <<-SHELL
  cd /vagrant
  bash docker_build.sh
  SHELL