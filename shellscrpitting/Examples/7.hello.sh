#!/bin/sh

# shell command line arguments example script program
IFS='$'  #it is used to join all arguments in  this $* 
echo "read command start here"
read var
echo $var
echo "read command end here"

echo "No. of arguments: $#"
echo "Shell script name:$0"
echo "Shell name:$SHELL"
echo "1st arg:$1"
echo "2nd arg:$2"
echo "All arg:$@"
echo "All arg:$*"
