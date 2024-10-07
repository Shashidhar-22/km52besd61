#!/bin/sh

# This example shows how to use functions in shell.

# function_name() {
#  statements
# }





#This is my example

fun()
{
	echo "inside fun function"
	echo $1
	echo $2
}

echo "fun starts here"
fun 12 13 14 15 	#it wil take only 2 arguments
echo "fun ends here"




