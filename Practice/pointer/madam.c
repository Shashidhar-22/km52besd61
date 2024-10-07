#include<stdio.h>
int *fun();
	int main()
{
	int *a;
	a=fun();
	printf("%d",*a);
}
int *fun()
{
	 int b;                 //static int b;
	 b=10;			//b=10;
			       //return &b; 
			       // now output is 10 
	return &b;
}

//output is warninig does't exicute (sigmintaion fault)
//so,change int b=10 t0 static int b=10;
//
