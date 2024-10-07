#include<stdio.h>
int main()
{
	int even=0,odd=0,i;
	int arr[50];
	for(i=0;i<=50;i++)
		arr[i]=i+1;
/*	for(i=0;i<=10;i++)
	{
		count=0;
		for(j=arr[i];j<=i;j++)
		{
			if(i%j==0)
				count++;
		}
			if(count==2)

		printf("prime numbers count are:%d\n",count);
	}*/

	for (int i=0;i<50;i++)
	{
		if(arr[i]%2==0)
			even=even+1;
		else
			odd=odd+1;
	}
			printf("Total Even numbers are:%d\n",even);
			printf("Total odd numbers are:%d\n",odd);
}
