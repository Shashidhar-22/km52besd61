#include<stdio.h>
int add (int a,int b);  ///decleration
int main()
{
	int a,b;		//function call
	printf("Enter any two integers:");
	scanf("%d%d",&a,&b);
	int s = add(a,b);
	printf("add is %d : ",s);
	return 0;
}
int add(int x,int y){				//defination
	return x+y;
}
