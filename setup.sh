#!/bin/bash

#Check if script is running as root
if [ "$EUID" -ne 0 ]; then
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
echo "Enable WM8731 sound card..."
if [ $(grep -c audioinjector-wm8731-audio /boot/config.txt) -eq "0" ]; then
	echo "dtoverlay=audioinjector-wm8731-audio" >> /boot/config.txt
fi
