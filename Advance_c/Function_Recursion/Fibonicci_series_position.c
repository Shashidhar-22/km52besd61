//THis program is to find fibonicci series position

#include<stdio.h>
int main()
{
	int n;
	printf("Enter position number to find value of fibonicci series:");
	scanf("%d",&n);
	printf("fib value is:%d",fib(n));
	printf("\n");
}

int fib(int n)
{
	if(n==1 || n==2)
	{
		return 1;
	}
	return fib(n-1)+fib(n-2);
}
