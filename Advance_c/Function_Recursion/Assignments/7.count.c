//7) Write a program to count the number of digits in a number.

#include<stdio.h>

int count(int n)
{
	if(n==0)
		return 0;
	return count(n/10)+1;

}

int main()
{
	int n,s;
	printf("ENter a number : ");
	scanf("%d",&n);
	s=count(n);
	printf(" count : %d\n",s);
}
