#!/bin/sh


if [  -e  $1 ] || [ -f $1 ] 
then
	echo "file exist"
else
	echo "file not exist"
fi

