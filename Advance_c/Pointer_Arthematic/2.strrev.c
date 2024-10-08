#include<stdio.h>
#include<string.h>
char *mystrrev (char *str);
int main()
	{
		char str[50];
		printf("Enter the string:");
		scanf("%s",str);
		printf("reverse string:%s\n",mystrrev(str));
		return 0;
	}
char *mystrrev(char *str)
{
	int i,j,temp;
	int len=strlen(str);
	
	//for(i=0;*(str+i)!='\0';i++)
	//	len++;

	for(i=0,j=len-1;i<len/2;i++,j--)
	{
		temp=str[i];
		str[i]=str[j];
		str[j]=temp;
	}
	return str;

}

