#include<stdio.h>
char *mystrlwr (char *s);
int main()
{
	char s[50];
	printf("Enter upper string:\n");
	scanf(" %50[^\n]s",s);
	char *string=mystrlwr(s);
	printf("The lower string is:%s\n",string);
	return 0;
}
char *mystrlwr(char *s)
{
	int i=0;
	for(i=0;*(s+i);i++)
	{
		if(*(s+i)>='A' && *(s+i)<='Z')
			*(s+i)+=32;
	}
	return s;
}
	
