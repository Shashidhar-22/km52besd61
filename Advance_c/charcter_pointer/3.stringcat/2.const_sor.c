/*3) Implement your own string concatenation function.
try calling the string copy function by sending the below as input:
1) string constant as destination and string variable as source
2) string variable as destination and string constant as source
3) string variable as destination and string variable as source
4) string constant as destination and string constant as source
note down the output and analyze the reasons

2) string constant as destination and string variable as source*/


#include<stdio.h>
#include<string.h>
void mystrcat( char*,const char*);
int main()
{
	char des[20],sor[20];
	printf("Enter string1:");
	scanf("%s",des);
	printf("Enter string2:");
	scanf("%s",sor);
	mystrcat(des,sor);
	printf("%s\n",des);
	return 0;
}
void mystrcat( char* des,const char* sor)
{
	int j;
	int k=strlen(des);
	for( j=0;sor[j]!='\0';j++)
	{
		*(des+k+j)=*(sor+j);
	}

	*(des+k+j)='\0';
}
/*
input:
shashi
dhar
output:shashidhar */

