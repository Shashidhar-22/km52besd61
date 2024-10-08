#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char *p=NULL;
	char *p1=NULL;
	p=(char *)malloc(10*sizeof(char));
	p1=(char *)malloc(10*sizeof(char));
	printf("Enter a string:");
	scanf("%s",p);
	strcpy(p1,p);
	printf("The copied string is :%s\n",p1);
	free(p);
}

