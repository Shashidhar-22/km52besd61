#!/bin/sh

for gs in *
do
	if [ -d $gs ]
	then 
		echo "$gs"
	fi
done
