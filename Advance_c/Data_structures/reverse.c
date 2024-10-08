#include<stdio.h>
#include<stdlib.h>

typedef struct student{
	int ID;
	char ch[10];
	struct student *next;
}stu;


stu * create_node()
{
	stu *N = malloc(sizeof(stu));
	printf("enter ID and name\n");
	scanf("%d%s",&N->ID,N->ch);
	N->next=NULL;
	return N;
}

stu *reverse(stu *H)
{
	stu *P,*Q,*R;
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
	H->next=NULL;
	return P;
}


void transversal(stu *T)
{
	while(T)
	{

		printf("%d%s\n",T->ID,T->ch);
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
			H=N;
		else
			L->next=N;
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
	printf("Before reverse:\n");
	transversal(H);
	H=reverse(H);
	printf("After reverse:\n");
	transversal(H);
	return 0;
}












