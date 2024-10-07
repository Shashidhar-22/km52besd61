
#include<stdio.h>
int main()
{
	int  i,j,k,r,c;
	printf("Enter no of row:\n");
	scanf("%d",&r);
	printf("Enter no of colunm:\n");
	scanf("%d",&c);
	int arr1[r][c];
	int arr2[r][c];
	int mul[r][c];
	printf("Enter the Elements of array Matrix 1 is %d*%d:\n",r,c);
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			scanf("%d",&arr1[i][j]);
		}
	}

	printf("The Matrix 1 is %d*%d:\n",r,c); 
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
	
			printf("%d\t",arr1[i][j]);
		}
		printf("\n");
	}


	printf("Enter the Elements of array Matrix 2 is %d*%d:\n",r,c);
	for(i=0;i<r;i++)
	{
		for (j=0;j<c;j++)
		{
			scanf("%d",&arr2[i][j]);
		}
	
	}
	printf("The matrix 2 is %d*%d:\n",r,c);
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("%d\t",arr2[i][j]);
		}
		printf("\n");
	}

	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			mul[i][j]=0;
			for(k=0;k<c;k++)
			{
			mul[i][j]+=arr1[i][k]*arr2[k][j];
			}
	
		}
	}

	printf("multiplication of two matrix is:\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("%d\t",mul[i][j]);
		}
		printf("\n");
	}
return 0;
}


































