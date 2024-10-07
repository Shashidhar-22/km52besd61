/*
#include<stdio.h>
int main()
{
	int i,prod=1;
	int arr[5]={10,4,1,6,2};
	for(i=0;i<5;i++)
	{
		prod*=arr[i];
	}
	printf("prod[]= {%d,%d,%d,%d,%d} \n",prod-432,prod-360,prod,prod-400,prod);
}
*/

//correct method is below
#include<stdio.h>
int main()
{
	int i,j;
	int p[5]={1,1,1,1,1};
	int arr[5]={10,4,1,6,2};
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			if(i!=j)
				p[i]*=arr[j];
		}
		printf("%d ",p[i]);
	}
}
