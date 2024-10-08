//In this programm delete at deffirent positions

#include<stdio.h>
#include<stdlib.h>

typedef struct student
{
	int id;
	char name[10];
	struct stu * next;
}stu;

stu *createnode();//declearing

void delete_pos(stu * T,int key1);
void delete_after(stu * T ,int pos);
void delete_before(stu * T,int key);


void delete_pos(stu * T,int key1)
{
	stu *S=T->next;
	printf("Enter a node to delete at position:");
	scanf("%d",&key1);
	while(S && S->id!=key1)
	{
		T=T->next;
		S=S->next;
	}
	T->next=S->next;
	free(S);
}


void delete_before(stu * T,int key)
{
	stu *S=T->next;
	printf("Enter a key for before delete:");
	scanf("%d",&key);
	while(S && S->id!=key)
	{
		T=T->next;
		S=S->next;
	}
	T->next=S->next;
	free(S);
}

void delete_after(stu * T ,int pos)
{
	printf("Enter node after position:");
	scanf("%d",&pos);
	stu *S=T;
	while(T->id!=pos)
	{
		T=T->next;
	}
	T->next=S->next;
	free(S);
}

stu *createnode()
{
	stu * N = malloc(sizeof(stu));
	printf("Enter id and name:\n");
	scanf("%d%s",&N->id,N->name);
	N->next=NULL;
	return N;
}

stu * list()
{
	stu * N=NULL,*H=NULL,*L=NULL;
	char ch='y';
	while(ch!='n')
	{
		N=createnode();
		if(H == NULL)
		{
			H=N;
		}
		else
		{
			L->next = N;	
		}
		L = N;
		printf("Create new node (Y/N)");
		scanf("\n%c",&ch);

	}
	return H;
}

void Travel(stu * T)
{
	while(T)
	{
		printf("%d\t%s\t%p\n",T->id,T->name,T->next);
		T = T->next;

	}
}


int main()
{
	stu *H;
	H=list();
	int n,key,pos,key1,s;
	printf("chose options\n1.node delete at position\n2.node delete before\n3.node delete after postion\n4.exit\n");
	while(1)
	{
		printf("select from above options:");
		scanf("%d",&s);
		switch(s)
		{
		case 1:	delete_pos( H,key1);
			Travel(H);break;
		case 2:delete_after(H , pos);
			Travel(H);break;
		case 3:	delete_before(H, key);
			Travel(H);break;
		case 4:exit (0);
			break;
		}
	}
	return 0;
}
