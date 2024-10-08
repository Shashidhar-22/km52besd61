#include<stdio.h>
#include<string.h>
char *mystrrev(char*);
int main()
{
	char string[10];
	printf("Enter a string:");
	scanf("%s",string);
        char *revstr = mystrrev(string);
	printf("%s\n",revstr);
}
char *mystrrev(char *string)
{
	char temp;
	int i,j;
	int s = strlen(string);
	for(i=0,j=s-1;i<s/2;i++,j--)
	{
		temp=string[i];
		string[i]=string[j];
		string[j]=temp;
	}
        return string;

}
