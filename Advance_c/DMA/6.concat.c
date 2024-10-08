#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char *concat(char *,char *);
int main()
{
	char *str1=(char*)malloc(10*sizeof(char));
	char *str2=(char*)malloc(10*sizeof(char));
	printf("Enter the string1:");
	scanf(" %[^\n]s",str1);
	printf("Enter the string2:");
	scanf(" %[^\n]s",str2);
	char *str3=(char *)malloc(20*sizeof(char));
	str3=concat(str1,str2);
	printf("%s\n",str3);
	return 0;
}

char *concat (char *str1,char *str2)
{
	int i,j,m,n;
	printf("Enter n and m:n");
	scanf("%d%d",&n,&m);
	for(i=n,j=0;j<m;i++,j++)
	{
		str1[i]=str2[j];
	}
	str1[i]='\0';
	return str1;

}
