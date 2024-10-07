//matrix addition and subtarction
#include<stdio.h>
int main()
{
	int r=3,c=3,i,j;
	int arr1[r][c];
	int arr2[r][c];
	int add[r][c];
	int sub[r][c];
	printf("Enter 1 array elements : \n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			scanf("%d",&arr1[i][j]);
			
		}
	}
	printf("Enter 2 array elements : \n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			scanf("%d",&arr2[i][j]);
		}
	}
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			add[i][j] = arr1[i][j] + arr2[i][j];
			sub[i][j] = arr1[i][j] - arr2[i][j];
		}
	}
	printf("Aditiom is :\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("%d ",add[i][j]);
		}
		printf("\n");
	}

	printf("Sub is : \n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("%d ",sub[i][j]);
		}
		printf("\n");
	}
	return 0;
}
