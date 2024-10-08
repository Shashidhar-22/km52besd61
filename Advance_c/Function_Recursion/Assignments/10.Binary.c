//10) WAP to print Binary equivalent of an integer using recursion without using any array variable.


#include<stdio.h>
void int_to_bin(int n)
{
	if(n==0)
		return;
//	printf("%d",n%2);
	int_to_bin(n/2);
	printf("%d",n%2);
}


int main()
{
	int n;
	printf("Enter an decimal/integer number : ");
	scanf("%d",&n);
	printf("Binary is : ");
	int_to_bin(n);
	printf("\n");
	
}
