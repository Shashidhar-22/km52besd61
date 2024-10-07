//6.Reverse of string without using library functions.
#include<stdio.h>
#include<string.h>
char *mystrrev(char str[] )
{
	int i,j;
	char temp;
	int s=strlen(str);
	for(i=0,j=s-1;i<s/2;i++,j--)
	{
		temp=str[j];
		str[j]=str[i];
		str[i]=temp;
	}
	return str;

}
int main()
{
	char str[20];
	printf("enter astring:\n");
	scanf(" %[^\n]s",str);
	printf("reverse string is:%s\n",mystrrev(str));
	return 0;
}
