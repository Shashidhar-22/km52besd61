#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,i;
	printf("Enter the size of string:");
	scanf("%d",&n);
	char *p=NULL;
	p=(char *)malloc(n*sizeof(char));
	printf("Enter a string:");
	scanf("%s",p);
	for(i=0;i<n;i++){
	printf("%c",p[i]);}
	free(p);
}
