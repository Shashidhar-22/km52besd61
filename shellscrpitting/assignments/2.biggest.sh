#!/bin/sh
if [ $# -eq 3 ]
then
	if [ $1 -gt $2 ] && [ $1 -gt $3 ]
	then
			echo "1st argument is big"
		fi
	if [ $2 -gt $3 ]  &&  [ $2 -gt $1 ] 
	then
		echo "2nd argument is big"
	fi

	if [ $3 -gt $1 ] && [ $3 -gt $2 ]
	then
		echo "3rd argument is big"
	fi
else
	echo "Invalid operators Enter only 3 arguments" 
	echo " '<arg1>' '<arg2>' '<argv3>' "

fi

