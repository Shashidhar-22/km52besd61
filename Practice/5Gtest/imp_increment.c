#include<stdio.h>
int main()
{
	int a=3;
	int res=a++ + ++a + a++ + ++a;//first precedence is always unary ++
	printf("%d\n",res);
	return 0;
}
