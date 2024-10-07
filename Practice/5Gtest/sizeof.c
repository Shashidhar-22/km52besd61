#include<stdio.h>
int main()
{
	char * str="hello world";
	char s[]="hello world";
	printf("constant string pointer:%ld\n character array :%ld\n",sizeof(str),sizeof(s));

	return 0;
}
