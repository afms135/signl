#!/bin/sh

#Check if script is running as root
if ![ $(id -u) = 0 ]; then
	echo "Script needs to be run as root!"
	exit 1
fi

#Installing required prerequisites
echo "Installing required prerequisites..."
apt-get update
apt-get -y install jackd2 libjack-jackd2-dev git
if [ $? -ne 0 ]; then
	echo "apt-get failed (Are you connected to the internet?)"
fi

#Sound card/HW setup
echo "Configuring Hardware..."
echo "Disabling internal sound card..."
sed -i "s:dtparam=audio:#dtparam=audio:" /boot/config.txt
