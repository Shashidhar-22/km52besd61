#include<stdio.h>
#include<stdlib.h>
int i;
typedef struct student{
	int ID;
	char ch[10];
	struct student *next;
}stu;

stu* create_node();
stu* addres;

stu* create_node()
{

	stu *N = malloc(sizeof(stu));
	printf("enter ID and name\n");
	scanf("%d%s",&N->ID,N->ch);

	N->next=NULL;
	if(i==2)
	{
		addres=N;
	}
	return N;
}


void transversal(stu *T)
{
	while(i<24)
	{
		printf("%d%s\n",T->ID,T->ch);
		T=T->next;
		i++;
	}
}


stu* creationlist()
{
	stu *H =NULL,*N =NULL,*L=NULL;
	while(i<=6)
	{
		N=create_node();

		if(H==NULL)
			H=N;
		else
			L->next=N;
		L=N;
		if(i==6)
		{
			N->next=addres;
		}
	i++;
	}
	return H;	
}

int main()
{
	stu *H;
	H=creationlist();
	transversal(H);
	return 0;
}












