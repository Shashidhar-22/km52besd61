#include<stdio.h>
int main()
{
	int arr[10];
	int i;
	for (i=0;i<10;i++)
	{
		printf("%d,%p\n",arr[i],&arr[i]);
	}
	return 0;
}
