#!/bin/bash
RED='\033[0;31m'
NC='\033[0m' # No Color

#Check if script is running as root
if [ "$EUID" -ne 0 ]; then
	echo -e "${RED}Script needs to be run as root!${NC}"
	exit 1
fi

#Installing required prerequisites
echo -e "${RED}Installing required prerequisites...${NC}"
apt-get update
apt-get -y install jackd2 libjack-jackd2-dev git
if [ $? -ne 0 ]; then
	echo -e "${RED}apt-get failed (Are you connected to the internet?)${NC}"
fi

#Sound card/HW setup
echo -e "${RED}Configuring Hardware...${NC}"
echo -e "${RED}Disabling internal sound card...${NC}"
sed -i "s:dtparam=audio:#dtparam=audio:" /boot/config.txt
echo -e "${RED}Enable WM8731 sound card...${NC}"
if [ $(grep -c audioinjector-wm8731-audio /boot/config.txt) -eq "0" ]; then
	echo "dtoverlay=audioinjector-wm8731-audio" >> /boot/config.txt
fi
echo -e "${RED}Enable spidev...${NC}"
sed -i "s:#dtparam=spi=on:dtparam=spi=on:" /boot/config.txt

#Download git submodules
echo -e "${RED}Downloading submodules...${NC}"
git submodule update --init

#Build software
echo -e "${RED}Building software...${NC}"
make -C ./Software/
