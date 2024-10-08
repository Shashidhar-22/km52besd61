#include<stdio.h>
#include<string.h>
char *mystrcpy (char *des, char *sor);
int main()
{
	char sor[50];
	char des[50];
	printf("Enter the string:\n");
	scanf("%50s",sor);
	mystrcpy(des,sor);
	printf("destination string is : %s\n",des);

}

char *mystrcpy(char *des,char *sor)
{

	int i=0;
	for(;*(sor+i)!='\0';i++)
	{
		*(des+i)=*(sor+i);
	}
	des[i]='\0';
	return des;
}

