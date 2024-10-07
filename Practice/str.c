#include<stdio.h>
#include<string.h>
int main()
{
	char str[]="hello\0\0\0\0";
	char str1[]="hello\n\n\n\n";
	
	printf("%ld\t%ld\n",sizeof(str),strlen(str));
	printf("%ld\t%ld\n",sizeof(str1),strlen(str1));
}
