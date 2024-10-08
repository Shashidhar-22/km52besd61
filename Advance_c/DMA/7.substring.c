#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char *fun(char*,char*,char*);
int main()
{
	int a,b,c;
	printf("Enter size of string:");
	scanf("%d",&a);
	char *string = (char *)malloc(a*sizeof(char));
	printf("Enter the String:");
	scanf(" %[^\n]s",string);

	printf("Enter size of substring:");
	scanf("%d",&b);
	char *sub=(char*)malloc(b*sizeof(char));
	printf("Enter the sub String:");
	scanf(" %[^\n]s",sub);

	printf("Enter size of replace string:");
	scanf("%d",&c);
	char *replace= (char *)malloc(c*sizeof(char));
	printf("Enter the replace String:");
	scanf(" %[^\n]s",replace);

	printf("output string is :%s\n",fun(string,sub,replace));
}

char *fun(char *string, char *sub,char *replace)
{
	//char *temp1= (char*)malloc(50*sizeof(char));
	//char *temp2= (char*)malloc(50*sizeof(char));
	//while(NULL!=strstr(string,sub))
	//{
	//	temp1=strstr(string,sub);
	//	strcpy(temp2,temp1);
	//	*(string+(temp1-string))=0;  
	//	strcat(string,replace);
	//	strcat(string,temp2+strlen(sub));
	//}
	int i=0,j=0,k=0,count=0,x,y,m=0;
	x=strlen(string);
	y=strlen(replace);
	while(string[i])
	{
		if (string[i]==sub[j])
		{
		count++;
		}
		i++;
	}
	m=(x+(count*y)-count+1);
	i=0;
	j=0;

	char *new=(char*)malloc(m*sizeof(char));
	while(string[i])
	{
		if(string[i]!=sub[j])
		{
			new[k]=string[i];
			k++;
			i++;
		}
		else if (string[i]==sub[j])
		{
			strcat(new,replace);
			k=k+strlen(replace);
			i++;	
		}
	}
	new[k]='\0';
	return new;
}




