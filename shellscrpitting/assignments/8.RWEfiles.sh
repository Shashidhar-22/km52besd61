#!/bin/sh

for i in *
do
	if [ -r $i ] && [ -w  $i ] && [ -x $i ]
	then
		echo "$i"
	else
		echo "Error"
	fi
done
