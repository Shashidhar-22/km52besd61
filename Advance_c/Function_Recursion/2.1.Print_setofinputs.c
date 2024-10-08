
//Multiple output from Recursion Function

#include<stdio.h>
void print(int n)
{
	if(n==0)
		return ;//termination condition
	printf("%d",n);//5 4 3 2 1	
	print(n-1);	//decrement  AND when we using void function just put functionname   no need of return in void
}


int main()
{
	int n=5; //initilization
	print(n);
}
