#!/bin/sh
if [ $# -eq 0 ]
then
	echo "NO arguments privided"
exit 1
fi
for i in  $*
do
	if [ -e $i ]
	then
		echo "$i"
		if [ -f $i ]
		then
			cat $i | wc -l
		else
			echo "It is a directory"
		fi
	else
		echo "$i"
		echo ""No such file of directory
	fi
done
