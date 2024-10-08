#include<stdio.h>
char *mystrchr (char *s,char c);
int main()
{
	char s[50]="abc";
//	char c;
//	printf("Enter a string:\n");
//	scanf(" %50[^\n]s",s);
//	printf("Enter a character to search:\n");
//	scanf("%s",&c);
	printf("string address %p\n",s);
	printf("string with character addrerss %p\n ",mystrchr(s,'c'));
	return 0;
}
char *mystrchr(char *s,char c)
{
	while(*s!='\0')
	{
	if(*s==c)
	return s;
	s++;
	}
}
	

