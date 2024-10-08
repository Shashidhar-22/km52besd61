#include<stdio.h>
#include<stdlib.h>

typedef struct student{
	int ID;
	char ch[10];
	struct student *next;
}stu;

stu* create_node();
//void transversal();


stu * insertnode(stu *T,int pos)
{
       	int i=1;
        stu *N=create_node();
	if(pos ==1)
	{
		N->next=T;
		return N;
	}
	else
	{
        while(i<pos-1)
        {
                T=T->next;
                i++;
        }

                N->next=T->next;
                T->next=N;
	}
}
 
stu* create_node()
{
	stu *N = malloc(sizeof(stu));
	printf("enter ID and name\n");
	scanf("%d%s",&N->ID,N->ch);
	N->next=NULL;
	return N;
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
	transversal(H);
	int pos;
	printf("ENter the node position\n");
	scanf("%d",&pos);
	H=insertnode(H,pos);
	transversal(H);
	return 0;
}












