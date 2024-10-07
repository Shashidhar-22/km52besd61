
#include<stdio.h>
void fun(int arr[][4][2]);
int main()
{
	//int arr[3][4][2] = {1,2,3,4,5,6,7,8};
	int arr[3][4][2]={{{1,2},{3}},{{4,5,6},{7,8}},{{9,6},{1,1}}};
	fun(arr);
	return 0;
}
void fun(int arr[][4][2])
{
	int i,j,k;
	for(i=0;i<3;i++)
	{
		for(j=0;j<4;j++)
		{
			for(k=0;k<2;k++)
			{
				printf("%d",arr[i][j][k]);
			}
			printf("\n");
		}
		printf("\n");
	}
	printf("\n");
}
