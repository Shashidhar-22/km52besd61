#include<stdio.h>

void swap(  char *a, char *b);

int main()
{
	char ch1,ch2;
	printf("Enter 2 characters\n:");
	scanf("%s %s",&ch1,&ch2);

	swap(&ch1,&ch2);
	printf("%c %c\n",ch1,ch2);
	return 0;
}


void swap( char *a,  char *b)
{
	char temp;
	temp=*a;
	*a=*b;
	*b=temp;
	//printf("%s %s\n",*str1,*str2);
}
