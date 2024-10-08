

#include<stdio.h>

int a,b=1,c;
void fib(int n);
int main()
{

	int n;
	printf("Enter number to find fibonicci series:");
	scanf("%d",&n);
	printf("%d %d ",a,b);
	fib(n);
	printf("\n");
}

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
