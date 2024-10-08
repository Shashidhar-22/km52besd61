#include<stdio.h>
#include<stdlib.h>

typedef struct student{
	int ID;
	char ch[10];
	struct student *next;
	struct student *previous;

}stu;

stu* create_node();
//void transversal();


void insertnode(stu *T,int pos)
{
	stu *S;
	S=T->next;
	int i=1;
	while(i<pos-1)
	{
		T=T->next;
		S=S->next;
		i++;
	}
	stu *N=create_node();
	 N->next=T->next;
	N->previous=S->previous;
	S->previous=N;
	T->next=N;
}

stu* create_node()
{
	stu *N = malloc(sizeof(stu));
	printf("enter ID and name\n");
	scanf("%d%s",&N->ID,N->ch);
	N->next=NULL;
	N->previous=NULL;
	return N;
}

void transversal(stu *T)
{
	while(T)
	{

		printf("%d %s\n",T->ID,T->ch);
		T=T->next;
	}
}

stu* creationlist()
{
	stu *H =NULL,*N =NULL,*L=NULL;
	char ch='y';

	while(ch!='n')
	{
		N=create_node();

		if(H==NULL)
		{
			H=N;
		}
		else
		{
			L->next=N;
			N->previous=L;
		}
		L=N;
		printf("create another ?(y/n)");
		scanf("\n%c",&ch);
	}
	return H;	
}


int main()
{
	stu *H;
	H=creationlist();
	transversal(H);
	int pos;
	printf("Enter the node position\n");
	scanf("%d",&pos);
	insertnode(H,pos);
	printf("After inserting:\n");
	transversal(H);
	return 0;
}












