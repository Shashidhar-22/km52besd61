#include<stdio.h>
int rev(int input1)
{
	int i,rem,rev=0;
	while(input1!=0)
	{
		rem=input1%10;
		rev=rev*10+rem;
		input1=input1/10;

	}
	return rev;
}
int main()
{
	int input1;
	printf("enter a interger:");
	scanf("%d",&input1);
	printf("output:%d\n",rev(input1));
	return 0;

}
