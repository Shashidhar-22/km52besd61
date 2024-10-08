///8) Implement string length function using recursion.

#include<stdio.h>
int length;
void strlength(char str[],int i)
{
	if(str[i]=='\0')
		return ;
	else
		length++;
	strlength(str,i+1);

}
int main()
{
	char str[20];int i=0;
	printf("Enter a string to find out the length:");
	scanf(" %[^\n]s",str);
	strlength(str,i);
	printf("length of string is : %d\n",length);
}

