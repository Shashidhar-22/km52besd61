#include<stdio.h>
int main()
{
	int arr[10]={1,2,3,4,5};
	int *p=&arr[2];
	++*p;
	printf("%d",arr[2]++);
}
