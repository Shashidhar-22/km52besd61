//9) Write a recursive function that returns the reverse of an integer.
int rem;
#include<stdio.h>
int intrev(int n)
{
	int rev;
	if(n==0)
		return rem;
	else
		rev=n%10;
		rem=rem*10+rev;
		return intrev(n/10);
}


int main()
{
	int n,s;
	printf("Enter an integer:");
	scanf("%d",&n);
	s=intrev(n);
	printf("Reverse of an integer : %d\n",s);
}
