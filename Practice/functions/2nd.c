#include<stdio.h>
void nameste();
void bonjour();
 int main()
	{
	printf("enter f or i for indian : ");
	char c;
	scanf("%c",&c);
	if (c=='i')
		nameste();
	else
		bonjour();
	
	return 0;
	}
	void nameste(){
		printf("Nameste\n");
	}
	void bonjour(){

	printf("Bonjour\n");
	}

