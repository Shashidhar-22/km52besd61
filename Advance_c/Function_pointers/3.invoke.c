#include<stdio.h>
int main()
{
	int a,b;
	int add(int ,int);
	int sub(int,int);
	int mul(int,int);
	int div(int,int);
	int mod(int,int);
	int invokeptr(int(*fptr)(int ,int),int a,int b);
	printf("Enter two integers:");
	scanf("%d%d",&a,&b);
	int (*fptr)(int ,int);
	char c;
	printf("Enter the choice of calculation:\n");
	scanf(" %c",&c);

	switch(c)
	{
	default  :
		printf("Invalid operand\n.....:");
	case '+' : 
		invokeptr(add,a,b);
		break;
	case '-' : 
		invokeptr(sub,a,b);
		break;
	case '*' : 
		invokeptr(mul,a,b);
		break;
	case '%' : 
		invokeptr(div,a,b);
		break;
	case '/' : 
		invokeptr(mod,a,b);
		break;
	}

	return 0;
}

int invokeptr(int (*fptr)(int,int),int a,int b)
{
	printf("%d\n",fptr(a,b));
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










