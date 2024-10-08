#include<stdio.h>
int main()
{
	int a,b;
	int add(int ,int);
	int sub(int,int);
	int mul(int,int);
	int div(int,int);
	int mod(int,int);
	int invokeptr(int (*fptrarr[])(int ,int),int a,int b,char c);
	printf("Enter two integers:");
	scanf("%d%d",&a,&b);
	int (*fptrarr[])(int ,int)={add,sub,mul,div,mod};
	char c;
	printf("Enter the choice of calculation:\n");
	scanf(" %c",&c);

	switch(c)
	{
		default:
			printf("Invalid operand...:\n");
		case '+' : 
			invokeptr(fptrarr,a,b,c);
			break;
		case '-' : 
			invokeptr(fptrarr,a,b,c);
			break;
		case '*' : 
			invokeptr(fptrarr,a,b,c);
			break;
		case '%' : 
			invokeptr(fptrarr,a,b,c);
			break;
		case '/' : 
			invokeptr(fptrarr,a,b,c);
			break;
	}

	return 0;
}

int invokeptr(int (*fptrarr[])(int,int),int a,int b,char c)
{ 
	if(c == '+')
		printf("%d\n",fptrarr[0](a,b));
	if(c == '-')
		printf("%d\n",fptrarr[1](a,b));
	if(c == '*')
		printf("%d\n",fptrarr[2](a,b));
	if(c == '%')
		printf("%d\n",fptrarr[3](a,b));
	if(c == '/')
		printf("%d\n",fptrarr[4](a,b));


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











