//) Write a program to reverse a string , using pointer arthematic method.

#include<stdio.h>
#include<string.h>
void stringreverse(char *str,char *end)
{
	char temp;
	if(str>end)
		return;

		temp=*str;
		*str=*end;
		*end=temp;
		stringreverse(str+1,end-1); //if u r using void don't use return(function name),,just put function name.
}

int main()
{
	char str[20],*end;
	printf("Enter a string:");
	scanf(" %[^\n]s",str);
	end=str;
	while(*end!='\0')
	{
		end++;
	}
	--end;
	stringreverse(str,end);
	printf("After reverse string is : %s\n",str);

}
