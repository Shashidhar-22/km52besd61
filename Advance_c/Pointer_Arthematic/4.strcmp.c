#include<stdio.h>
//#include<string.h>
int mystrcmp(char *str1,char *str2);
int main()
{
	int s;
	char str1[50];
	char str2[50];
	printf("Enter 1st string:" );
	scanf("%50[^\n]s",str1);
	printf("Enter 2nd string:");
	scanf(" %50[^\n]s",str2);
	s=mystrcmp(str1,str2);
	if (s==0)
		printf("Both are strings are same");
	 if(s<0)
		printf("First is smaller then second");
	 if (s>0)
		printf("First is bigger then second");
	return 0;
}

int mystrcmp(char *str1,char *str2)
{

	int i;
	for(i=0;*(str1+i)!='\0';i++)
	{
		if (*(str1+i)!=*(str2+i))
			return (*(str1+i)-*(str2+i));
			}
	return 0;


}

