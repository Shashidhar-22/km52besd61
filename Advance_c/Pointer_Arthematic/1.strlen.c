#include<stdio.h>
#include<string.h>
int mystrlen(char *str);
int main()
{
	char str[]="shashidhar";
       int s=mystrlen(str);
	printf("%d\n",s);
}
int mystrlen (char *str)
{
	int i=0;
	while(*str!='\0')
	{
		i++;
		str++;
	}
	return i;
}


