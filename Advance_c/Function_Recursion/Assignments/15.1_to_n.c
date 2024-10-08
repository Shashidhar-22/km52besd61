//15) write a program to print first n numbers (1 to n) using a recursive main function.
//Multiple output from Recursion Function

#include<stdio.h>
void print(int n)
{
	if(n==0)
		return ;//termination condition

	print(n-1);     //decrement  AND when we using void function just put functionname   no need of return in void
	printf("%d\n",n);//1 2 3 4........n	
}


int main()
{
	int n; //initilization
	printf("ENter a number : ");
	scanf("%d",&n);
	print(n);
}
