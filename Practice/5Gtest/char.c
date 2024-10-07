#include<stdio.h>
int main()
{
	char *ptr;
	char p[]="abcdefg";
	ptr=p;
	ptr+=5;
	printf("%s\n",ptr);
}
