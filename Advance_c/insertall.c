#include<stdio.h>
#include<stdlib.h>

typedef struct student
{
	int id;
	char name[10];
	struct stu * next;
}stu;

stu *createnode();//declearing
void insert_after(stu * T ,int pos);
stu * insert_pos(stu * T,int n);
void before_insert(stu * T,int key);


stu * insert_pos(stu * T,int n)
{
	int i=1;
	stu * N = createnode();
	printf("Enter node at position:");
	scanf("%d",&n);
	if(n == 1)
	{
		N->next=T;
		return N;

	}
	else
	{
	while(i<n-1)
	{
		T = T->next;
		i++;
	}
	N->next=T->next;
	T->next=N;
	}
}

void before_insert(stu * T,int key)
{
	stu *S=T->next;
	printf("Enter a key for before insert:");
	scanf("%d",&key);
	while(S && S->id!=key)
	{
		T=T->next;
		S=S->next;
	}
	stu * N = createnode();
	N->next=T->next;
	T->next=N;
}

void insert_after(stu * T ,int pos)
{
	printf("Enter node after position:");
	scanf("%d",&pos);
	while(T->id!=pos)
	{
		T=T->next;
	}
	stu * N = createnode();
	N->next=T->next;
	T->next=N;
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

stu * reverse(stu *H)
{
	stu *P=NULL,*Q=NULL,*R=NULL;
	P=Q=R=H;
	Q=Q->next;
	R=Q->next;
	while(Q)
	{
		Q->next=P;
		P=Q;
		Q=R;
		if(R)
			R=R->next;
	}
	H ->next = NULL;
	return P;
}


int main()
{
	stu *H;
	H=list();
	int n,key,pos,key1,s;
	printf("chose options\n1.node insert at position\n2.node insert before\n3.node insert  after postion\n4.reverse\n5..exit");
	while(1)
	{
		printf("select from above options:");
		scanf("%d",&s);
		switch(s)
		{
		case 1:H=insert_pos(H, n);
			Travel(H);break;
		case 2: before_insert(H, key);
			Travel(H);break;
		case 3:	insert_after(H, key);
			Travel(H);break;
		case 4:H=reverse(H);
		       Travel(H);break;
		case 5:exit (0);
			break;
		}
	}

	return 0;
}

