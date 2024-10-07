#define r 3
#define c 4
#include<stdio.h>
int main()
{
	int  i,j;
	int arr[r][c];
	int arr1[c][r];
	printf("Enter the Elements of array 3*4:\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			scanf("%d",&arr[i][j]);
			arr1[j][i]=arr[i][j];
		}
	}
	printf("The Matrix before Transpose 3*4:\n"); 
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
	
			printf("%d\t",arr[i][j]);
		}
		printf("\n");
	}

	printf("The Transpose of Matrix is 4*3:\n");
	for(i=0;i<c;i++)
	{
		for (j=0;j<r;j++)
		{
			printf("%d\t",arr1[i] [j]);
		}
		printf(" \n");
	}
	return 0;

}

