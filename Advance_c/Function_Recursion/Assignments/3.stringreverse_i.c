//) Write a program to reverse a string , using index method.
#include<stdio.h>
#include<string.h>

void stringreverse(char str[],int i,int size)
{
	char temp;
	if(i<size)
	{
		temp=str[i];
		str[i]=str[size];
		str[size]=temp;
		 stringreverse(str,i+1,size-1); //if u r using void don't use return(function name),,just put function name.
	}
}
int main()
{
	char str[20];
	int size,i=0;
	printf("Enter a string:");
	scanf(" %[^\n]s",str);
	size=strlen(str)-1;
	stringreverse(str,i,size);
	printf("After reverse string is:%s\n",str);

}
