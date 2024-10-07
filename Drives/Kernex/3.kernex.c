#include<stdio.h>
int main()
{
	int s=10;
	int *ptr=&s;
	int **pptr=s;
	printf("%d\n",pptr);

	return 0;

}

