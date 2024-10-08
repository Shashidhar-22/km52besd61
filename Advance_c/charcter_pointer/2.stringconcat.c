#include<stdio.h>
int main()
{
	int mystrcmp(const char*,const char*);
	char str1[20],str2[20];
	printf("Enter the string 1:");
	scanf("%s",str1);
	printf("Entern the string 2:");
	scanf("%s",str2);
	int s = mystrcmp(str1,str2);
	if(s<0)
	printf("2nd string is big\n");
	if(s>0)
	printf("1st string is big\n");
	if(s==0)
		printf("both are same\n");
}
int mystrcmp(const char* des,const char* sor)
{
	int i;
	for(i=0;*(des+i)!='\0';i++)
	{
		if (*(des+i)!=*(sor+i))
		{
			return (*(des+i)-*(sor+i));
		}
		return 0;
	}
}


