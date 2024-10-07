#include<stdio.h>
#include<string.h>
int main()
{
	char *arr[10]={"Zero","one","two","three","four","five" ,"six","seven","eight","nine"};
	int n,rev=0,rem=0,r=0;
	printf("Enter a number : \n");
	scanf("%d",&n);
	while(n!=0)
	{
		rem=n%10;
		rev=rev*10+rem;
		n/=10;
	}
	printf("%d\n",rev);
	while(rev!=0)
	{
		r=rev%10;
		printf("%s ",arr[r]);
		rev/=10;
	}
	printf("\n");
	return 0;
}
