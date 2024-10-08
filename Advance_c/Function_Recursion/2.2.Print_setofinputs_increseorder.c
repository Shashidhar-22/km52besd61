
//Multiple output from Recursion Function

#include<stdio.h>
int main()
{
	int n=5;//initization
	print(n);
}
void print(int n)
{
	if(n==0)
		return ;//termination condition
	print(n-1);	//decrement
	printf("%d",n);//1 2 3 4 5


}

