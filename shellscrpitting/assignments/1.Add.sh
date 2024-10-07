#!/bin/sh

if [ $# = 2 ]
then
	echo "\$Addition of arguments above is : $(($1+$2))"
else
	echo "Invalid operator(Enter only 2 arguments)"
fi
