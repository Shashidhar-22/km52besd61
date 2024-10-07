#include<stdio.h>
int add(int,int);
int sub(int,int);
int main()
{
	int a,b,c;
	while(1)
	{
	printf("enter 2 numbers :");
	scanf("%d%d",&a,&b);
	printf("Enter choise\n1.addition\n2.subtractio\n3.exit");
	scanf("%d",&c);
	if (c==1)
		printf("add:%d\n",add(a,b));
	else if(c==2)
		printf("sub:%d\n",sub(a,b));
	else if(c==3)
		break;
	}
	return 0;
}



