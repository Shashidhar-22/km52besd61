#include<stdio.h>
#include<stdlib.h>
int main()
{
	int *p=(int *)malloc(sizeof(int));
	printf("Enter an integer:\n");
	scanf("%d",p);
	printf("The Entered value is:%d\n",*p);
	free(p);
}


