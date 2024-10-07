/*31-1-2014 Advance c grand test question 1:
using DMA 
1 st string:hello
2 nd string:world
output:hweolrrrod (merge sort alternate strings)
*/			
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,m;
	printf("Enter the size of string 1:");
	scanf("%d",&n);
	char *string1=(char *)malloc(n*sizeof(char));
	printf("Enter the size of string 2:");
	scanf("%d",&m);
	char *string2=(char *)malloc(m*sizeof(char));
	printf("Entre the string 1 : ");
	scanf(" %[^\n]s",string1);
	printf("Entre the string 2 : ");
	scanf(" %[^\n]s",string2);
	char *out=(char*)malloc(m+n+1*sizeof(char));
	int i=0,j=0,x=0;
	while(string1[i] && string2[j])
	{
		out[x++]=string1[i];
		out[x++]=string2[j];
		i++;
		j++;
	}
	while(string1[i])
	{
		out[x++]=string1[i];
		i++;
	}
	while(string2[j])
	{
		out[x++]=string2[j];j++;
	}
	out[x]='\0';
	printf("\nThe alternate sort from above strings is :: %s\n",out);
	free(out);
	free(string1);
	free(string2);
}




