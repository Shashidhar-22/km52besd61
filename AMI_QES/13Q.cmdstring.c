//13.   Write a program to take a string as input with command line argument and print the string and its length.
#include<stdio.h>
#include<stdlib.h>
int main(int argc ,char *argv[])
{
	int i=0;
	if(argc==2)
	{
		char *str=argv[1];

		while(str[i])
		{
			i++;
		}

		printf("Entered string length is :%d\n",i);
	//	printf("Entered string is :%s\n",str);
		printf("Entered string is :%s\n",argv[1]);
	}
	else
		printf("Invalid!\n Enter 1 argument in command line  <argv2>:\n");
return 0;
}
