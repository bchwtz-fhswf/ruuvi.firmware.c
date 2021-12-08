#!/bin/bash
export VAGRANT_DEFAULT_PROVIDER=libvirt
vagrant up
vagrant ssh -- -t 'cd /vagrant && bash docker_build.sh && exit; /bin/bash'