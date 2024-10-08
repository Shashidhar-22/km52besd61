//1) Write a program to find the factorial of a number.

#include<stdio.h>
static int a=1;
int factorial(int n)
{
	if(n==0)
		return a;
	a*=n;
	return factorial(n-1);
}

int main()
{
	int n;
	printf("ENter an number:");
	scanf("%d",&n);
	if(n>0)
	printf("Factorial of given number is : %d\n",factorial(n));
	else
		printf("sorry\nFactoraol is not possible for negative numbers\n");
}

