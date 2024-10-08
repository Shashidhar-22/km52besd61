// queue array

#include<stdio.h>
#define SIZE 3

int s[SIZE],rou;
int push(int s[],int top);
void pop(int s[],int *top,int *r);
int main()
{
	int r=-1,f=-1;
	int a=0;
	while(1)
	{
		printf("choose options 1)push 2)pop 3)exit\n");
		scanf("%d",&a);
		if(a==1)
			f = push(s,f);
		else if(a==2)
			pop(s,&f,&r);
		else if(a==3)
			break;
	}
	return 0;
}

int push(int s[],int top)
{
	int n;
	if(top==SIZE-1)
	{
		top=-1; rou++;
	}
	top++;
	if(s[top])
		printf("stack is full-%d\n",s[top--]);
	else
	{
		printf("enter the data to push\n");
		scanf("%d",&n);
		s[top]=n;
		printf("Top is like index : %d\n",top);
	}
	return top;
}


void pop(int s[],int *top,int *r)
{
	if(*r==SIZE-1)
		*r=-1;
	if( (*r!=*top || rou) && s[++*r])
	{
		printf("popping : %d\n",s[*r]);
		s[*r]=0;
	}
	else{
		printf("stack is empty\n");
	--*r;
	}

}
