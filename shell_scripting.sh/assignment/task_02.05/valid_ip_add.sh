#! /bin/bash

#1. In a file there are some IP V4 addresses available.Extract the valid IP V4 address from the file.

ip=0
files="ip_addr.txt"
while read line
do
	oct1=$(echo ${line} | tr "." " " | awk '{ print $1 }')
	if [ $oct1 -ge "0" ] && [ $oct1 -le "255" ]
	then
	oct2=$(echo ${line} | tr "." " "| awk '{ print $2 }')
	if [ $oct2 -ge "0" ] && [ $oct2 -le "255" ]
	then
	oct3=$(echo ${line} | tr "." " " | awk '{ print $3 }')
	if [ $oct3 -ge "0" ] && [ $oct3 -le "255" ]
	then
	oct4=$(echo ${line} | tr "." " " | awk '{ print $4 }')
	if [ $oct4 -ge "0" ] && [ $oct4 -le "255" ]
	then
	echo $line
	fi
	fi
	fi
	fi
done < $files
