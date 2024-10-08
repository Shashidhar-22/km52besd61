//  6) int stricmp (char s1[], char s2[]);

#include<stdio.h>
int stricmp(char s1[],char s2[]);
int main()
{
	int s;
	char s1[50];
	char s2[50];
	printf("enter a first character:\n");
	scanf("%50[^\n]s",s1);
	printf("enter a second character:\n");
	scanf(" %50[^\n]",s2);
	s = stricmp(s1,s2);
	if(s==0)
		printf("both are equal\n");
	if(s<0)
		printf(" first is smaller than second \n");
	if(s>0)
		printf(" first is bigger than second \n");
	return 0;
} 

int stricmp(char *s1,char *s2)
{
	int i;
	for(i=0;*(s1+i)!='\0';i++)
	{
		if(!((*(s1+i)==*(s2+i)+32)||(*(s1+i)+32==*(s2+i))) && (*(s1+i)!=*(s2+i)))
			return(*(s1+i)-*(s2+i));
	}
	return 0;

}
