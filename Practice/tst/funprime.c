#include<stdio.h>
int primeis(int n)
{
	int i,count=0;
	for(i=1;i<=n;i++)
	{
		if(n%i==0)
			count++;
	}
	if(count==2)
		return 1;
	else
		return 0;
}

int main()
{
	int n,prime;
	printf("Enter an integer:");
	scanf("%d",&n);
	prime=primeis(n);
	if(prime==1)
		printf("%d is prime number\n",n);
	else if(prime==0)
		printf("%d is not a prime number\n",n);
}

