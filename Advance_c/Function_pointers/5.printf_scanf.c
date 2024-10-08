#include<stdio.h>

int main()
{

	int a;
	int(*ptr)(const char *, ...);    //={printf,scanf};
	ptr=printf;
	ptr("Enter a number:");
	ptr=scanf;
	ptr("%d",&a);
	ptr=printf;
	ptr("your Entered number is : %d\n",a);

}
