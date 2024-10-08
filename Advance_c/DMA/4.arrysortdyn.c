#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	int temp,i,j,n;
	int *p=NULL;
	printf("Enter size of array:");
	scanf("%d",&n);
	p=(int *)malloc(n*sizeof(int));
	printf("Enter the array Elements:\n");
	for(i=0;i<n;i++){
	scanf("%d",&p[i]);}

	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if(p[j]>p[j+1])
			{
				temp=p[j+1];
				p[j+1]=p[j];
				p[j]=temp;
			}
		}
	}
	printf("The sorting elements are:");
	for(i=0;i<n;i++)
	{
		printf("%d ",p[i]);
	}
	printf("\n");
	free(p);
}


