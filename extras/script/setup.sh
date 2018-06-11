#!/bin/bash


#script to load and setup can0 on linux


while true; do
    read -p "Do you wish to setup can0 " yn
    case $yn in
        [Yy]* ) 
        
		echo "loading pcan"

		sudo modprobe pcan

		echo "loading socket can "

		sudo modprobe can

		echo " loading can0 up"

		sudo ifconfig can0 up 

		echo " setting up baudrate to 250k" 

		echo "i 0x011C e" > /dev/pcan32
        
        
        
        
         break;;
        [Nn]* ) sudo ifconfig can0 down
				echo " can0 is down" 
        exit;;
        * ) echo "Please answer yes or no.";;
    esac
done
