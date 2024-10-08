#include<stdio.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
	int i;
	printf("you have entered %d arguments\n",argc);
	for ( i=0;i<argc;i++)
	{
		printf("%s\n",argv[i]);
	}	
	int a=atoi(argv[1]);
	int b=atoi(argv[2]);
	int s=a+b;
	printf("%d\n",s);
}
