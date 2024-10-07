#include<stdio.h>
void fun(int *ptr)
{
	*ptr=30;
}
int main()
{
	int y=20;
	fun(&y);  //in function call for pointers (&) must mention otherwise it shows segimentation fault.
	printf("%d",y);
}

