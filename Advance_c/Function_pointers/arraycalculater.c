
#include<stdio.h>
int main()
{
	int add(int ,int);
	int sub(int,int);
	int mul(int,int);
	int div(int,int);
	int mod(int,int);
	int a,b,i;
	printf("Enter 2 Elements:");
	scanf("%d%d",&a,&b);
	int (*p[])(int ,int)={add,sub,mul,div,mod};
	printf("0.addition\n1.subtraction\n2.multiplication\n3.division\n4.module\n");
	printf("Enter the choice from above calc : ");
	scanf("%d",&i);
	printf("Result is:%d\n",(p[i])(a,b));
	return 0;
}

int add(int a,int b)
{
	return a+b;
}
int sub (int a,int b)
{
	return a-b;
}
int mul (int a,int b)
{
	return a*b;
}
int div (int a,int b)
{
	return a/b;
}
int mod(int a,int b)
{
	return a%b;
}




