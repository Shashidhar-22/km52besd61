//13) Print a single linked list from tail to head using recursive function, without reversing the linked list

#include<stdio.h>
#include<stdlib.h>

typedef struct student{
	int ID;
	char ch[10];
	struct student *next;
}stu;


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
	
	if(T==NULL)
	{
		return ;
	}	
		//printf("%d%s\n",T->ID,T->ch);
		transversal(T->next);//recursive call

		printf("%d%s\n",T->ID,T->ch);
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
	return 0;
}




