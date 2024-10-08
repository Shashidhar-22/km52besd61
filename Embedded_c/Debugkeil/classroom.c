#include<stdio.h>
void error(void);
int sum(int,int);
int change=0;

int main()
{
	int arg1=20,arg2=40;
	int i;
	for(i=0;i<10;i++)
	{
		if(arg1>arg2)
			arg2=sum(arg1,arg2);
		else
			arg1=sum(arg1,arg2);

	}
	error();

}
int sum(int a,int b)
{

	return a+b;
}
void error(void)
{
	int div=10;
	int res=div/change;


}
