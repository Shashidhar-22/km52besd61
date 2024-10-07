#include<stdio.h>
#include<string.h>
int chocolates(int input1, int input2[])
{
	int i,x,y=0,j;
	printf("enter the no of chocolates:\n");
	scanf("%d",&input1);
	printf("enter special values of chocolates:\n");
	for (i=0;i<input1;i++){
		scanf(" %d",&input2[i]);
	}
	x=input1;
	for (i=0;i<input1;i++)
	{
		for(j=0;j<x;j++)
		{
			y+=input2[j];
		}
		x--;
	}
	printf("%d\n",y);
}

int main()
{
	int input1,input2[input1];
	chocolates(input1,input2);
	return 0;
}

