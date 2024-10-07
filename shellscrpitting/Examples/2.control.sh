#example 1
#echo $PWD
#cd /home/shashi
#echo $PWD



#example 2
#if [ -w abc ] ;then
#	echo "abc file have write permission"
#else
#	echo "dont have write permission"
#fi



#example 3     about for loop
#for var1 in 0 1 2 3 4 5
#do
#	echo "\$var1:$var1"
#done



#example 4
#usage of for statement
#for i in *
#do
#	if grep -rq abc $i 
#	then
#		echo $i
#	fi
#done


#example 5

#i=1
#k=5
#while [ $i -le $k ]
#do
#	echo $i
#	i=$(expr $i + 1)
#done




#example 6

#usage of while statement
echo "Enter password"
read trythis

while [ "$trythis" != "secret" ]
do
	echo "sorry, try again"
	read trythis
done

echo "password authentiacation successfully!"

