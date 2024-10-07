#define r 3
#define c 4
#include<stdio.h>
int main()
{
	int  i,j;
	int arr1[r][c];
	int arr2[r][c];

	int add[r][c];
	int sub[r][c];

	printf("Enter the Elements of array Matrix 1 is 3*4:\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			scanf("%d",&arr1[i][j]);
		}
	}

	printf("The Matrix 1 is 3*4:\n"); 
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
	
			printf("%d\t",arr1[i][j]);
		}
		printf("\n");
	}


	printf("Enter the Elements of array Matrix 2 is 3*4:\n");
	for(i=0;i<r;i++)
	{
		for (j=0;j<c;j++)
		{
			scanf("%d",&arr2[i][j]);
		}
	
	}
	printf("The matrix 2 is 3*4:\n");
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
		add[i][j]=arr1[i][j]+arr2[i][j];
		sub[i][j]=arr1[i][j]-arr2[i][j];
		}
	}

	printf("Addition of two matrix is:\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("%d\t",add[i][j]);
		}
		printf("\n");
	}

	printf("Subtraction of two  Matrix is:\n"); 
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
	
			printf("%d\t",sub[i][j]);
		}
		printf("\n");
	}

	

			


		






}
