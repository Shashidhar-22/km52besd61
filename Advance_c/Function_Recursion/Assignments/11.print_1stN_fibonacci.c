//11) Print the first n Fibonacci numbers using a recursive function.
#include<stdio.h>
int a,b=1,c;
void fib(int n)
{
	c=a+b;
	printf("%d ",c);
	a=b;
	b=c;
	if(n==0)
		return ;
	fib(n-1);
}

int main()
{
	int n;
	printf("Enter a number to print fibnacci numbers : ");
	scanf("%d",&n);
	printf("%d %d ",a,b);
	fib(n);
	printf("\n");
}
