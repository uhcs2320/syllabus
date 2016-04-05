sudo apt-get -y update

#install g++ 4.8
sudo apt-get -y install python-software-properties
sudo add-apt-repository ppa:ubuntu-toolchain-r/test
sudo apt-get -y update
sudo apt-get -y install gcc-4.8 g++-4.8
sudo update-alternatives --remove-all gcc
sudo update-alternatives --remove-all g++
sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-4.8 20
sudo update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-4.8 20
sudo update-alternatives --config gcc
sudo update-alternatives --config g++

# install git
sudo apt-get -y install git

# create directories for homework assignments
cd /vagrant
mkdir -p hw0 hw1 hw2 hw3 hw4 hw5 hw6 hw7 hw8

# make tester globally executable
chmod +x /vagrant/tester/tester
echo "export PATH=$PATH:/vagrant/tester" >> /home/vagrant/.bashrc

# set start directory
echo "cd /vagrant" >> /home/vagrant/.bashrc
