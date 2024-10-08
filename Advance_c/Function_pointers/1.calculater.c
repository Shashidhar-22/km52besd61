#include<stdio.h>
int main()
{
	int add(int ,int);
	int sub(int,int);
	int mul(int,int);
	int div(int,int);
	int mod(int,int);
	int a,b;
	printf("Enter two integers:");
	scanf("%d%d",&a,&b);

	int (*p)(int ,int)=add;          //function pointer  
	printf("Addition is:%d\n",p(a,b));
	p=&sub;
	printf("Subtraction is:%d\n",(*p)(a,b));
	p=mul;
	printf("Multipication is :%d\n",p(a,b));
	p=div;
	printf("Division is :%d\n",p(a,b));
	p=mod;
	printf("Module is :%d\n",p(a,b));
	printf("%d\n",(*p)(a,b));
	return 0;
}

int add(int a,int b )
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




