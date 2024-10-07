#include<stdio.h>
int main()
{
	int a1,i,poe=1;
	printf("enter the lenth of arr");
	scanf("\n%d",&a1);
	int a[a1];
	printf("Enter the array element:\n");
	for(i=0;i<a1;i++)
		scanf("%d",&a[i]);
	for(i=0;i<a1;i++)
	{
		poe=poe*a[i];
		//	for (i=0;i<5;i++)
		printf("\narray element at index %d is:%d",i,poe);
	}
}
