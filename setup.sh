#!/bin/sh

#Check if script is running as root
if ![ $(id -u) = 0 ]; then
	echo "Script needs to be run as root!"
	exit 1
fi
