//14) write a program to print first n numbers (n to 1) using a recursive main function.

//Multiple output from Recursion Function

#include<stdio.h>
void print(int n)
{
	if(n==0)
		return ;//termination condition
	printf("%d\n",n);//n..... 2 1	
	print(n-1);     //decrement  AND when we using void function just put functionname   no need of return in void

}


int main()
{
	int n; //initilization
	printf("ENter a number : ");
	scanf("%d",&n);
	print(n);
}

