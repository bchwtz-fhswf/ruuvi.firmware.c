#!/bin/bash
export VAGRANT_DEFAULT_PROVIDER=hyperv
vagrant up
vagrant ssh -- -t 'cd /vagrant && sudo chown -R vagrant:vagrant /tmp && rsync --update --exclude=".vagrant/*" -v --recursive . /tmp/ && cd /tmp && bash docker_build.sh && sudo chown -R vagrant:vagrant . && rsync -v --recursive src/targets/ruuvitag_b/armgcc/ /vagrant/src/targets/ruuvitag_b/armgcc/ && exit; /bin/bash'
