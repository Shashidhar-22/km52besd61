#include<stdio.h>
int main()
{
	int i=0,j=0,x=0;
	char str1[10];
	char str2[10];
	char out[10];
	printf("Enter 2 strings : \n");
	scanf(" %[^\n]s",str1);
	printf("Enter 2nd : \n");
	scanf(" %[^\n]s",str2);
	for(; str1[i] && str2[j];i++,j++)
	{
		out[x++]=str1[i];
		out[x++]=str2[j];
	}
	printf(" output is : %s\n",out);
	return 0;
}
