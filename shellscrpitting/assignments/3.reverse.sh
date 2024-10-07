<<co   
#comment begin

 a=$1
reverse=0
if [ $# -ne 1 ]
then
	echo "Invalid argument (enter only one)"
else
	while [ $a -gt 0 ]
	do
		digit=$( expr $a%10 )
		reverse=$( expr $reverse * 10 + digit )
		a=$( expr $a / 10 )

	done

	echo "output:"
	echo "$reverse"

#else
#	echo "Invalid Enter only one argument"
fi

#comment end
co  


#!/bin/sh
echo "Enter a number"
read num
rev=0
	while [ $num -gt 0 ]
	do
		dig=$((num%10))
		rev=$((rev*10+dig))
		num=$((num/10))
	done
	echo "output:"
	echo  "$rev"

