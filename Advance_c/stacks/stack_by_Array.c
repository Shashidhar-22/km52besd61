//hello this stack it is imlemented by 2 ways Array and linkedlist (LIFO/last in first out) 
//Below method is implemented with Array method

#include<stdio.h>
#define SIZE 10
int push(int s[],int top);
int pop(int s[],int *top);

int main()
{
	int top=-1;
	int s[SIZE];
	int a=0;
	while(1)
	{
		printf("choose options 1)push 2)pop 3)exit\n");
		scanf("%d",&a);
		if(a==1)
			top = push(s,top);
		else if(a==2)
			top = pop(s,&top);
		else if(a==3)
			break;
	}

	return 0;
}

int push(int s[],int top)
{
	int n;
	if(top==SIZE-1)
		printf("stack is full\n");
	else{
		printf("enter the data to push\n");
		scanf("%d",&n);
		top++;
		s[top]=n;
		printf("Top is like index : %d\n",top);
	}
	return top;
}

int pop(int s[],int *top)
{
	if (*top == -1)
		printf("stack is empty\n");
	else{
		printf("popping : %d\n",s[*top]);
		--*top;
	}
	return *top;	
}

