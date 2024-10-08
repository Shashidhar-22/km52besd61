#include<stdio.h>
#include <stdlib.h>
#define SIZE 10

typedef struct student
{
	int ID;
	struct student *next;
} stu;

stu *createnode()
{
	stu *N=malloc(sizeof(stu));
	printf("Enter the value to store on heap:\n");
	scanf("%d",&N->ID);
	N->next=NULL;
}

stu *push(stu *T)
{
	stu *N=createnode();
	N->next = T;
	return N;
}
stu *pop(stu *D)
{
	stu *a=NULL;
	a=D->next;
	free(D);
	return a;
}
int main()
{
	int c=0;
	stu *H = NULL;
	int ch=1;

	while(ch!=3)
	{
		printf("choose: 1)push 2)pop 3)quit\n");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1:
				printf("value is going to be add in new node:");
				H=push(H);
				c++;
				break;
			case 2:
				if(c==0)
				{
					printf("No node is Available\n");
					break;
				}
				printf("retrive value is:%d\n",H->ID);
				H=pop(H);
				c--;
				break;
			default:
				printf("invalid input\n");
				exit(0);
		}
	}
	return 0;
} 


