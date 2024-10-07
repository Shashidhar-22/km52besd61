//16.   Find the size of a variable without using size of operator.
#include<stdio.h>
int size_ofint(int n );
int main()
{
	int n;
	printf("enter a number:");
	scanf("%d",&n);
	int g=size_ofint(n);
	printf("The size of int:%d\n",g);
	return 0;
}

int size_ofint(int n )
{
	int i=0;
	while(n)
	{
		//n=n<<1;
		i++;
		n=n<<1;
	}
	return i/8;
}
