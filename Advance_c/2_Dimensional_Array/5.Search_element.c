
#include<stdio.h>
int search(int r,int c, int arr[][c],int s,int *x,int*y);
int main()
{
	int r,c,s,i,j,x,y;
	printf("Enter row and colunm:\n");
	scanf("%d%d",&r,&c);
	int arr[r][c];
	printf("Enter array Elements:");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}

	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("%d\t",arr[i][j]);
		}
		printf("\n");
	}

	printf("Enter search element:");
	scanf("%d",&s);
	search(r,c,arr,s,&x,&y);

	if(x>=0 || y<=0)
		printf("Row index:%d  column index :%d\n",x+1,y+1);
	else
		printf("Elements not found\n");

}

int search(int r,int c,int arr[][c],int s,int *x,int*y)	
{
	int i,j;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			if (s==arr[i][j])
			{
				*x = i;
				*y = j;
			}

		}
	}
}
