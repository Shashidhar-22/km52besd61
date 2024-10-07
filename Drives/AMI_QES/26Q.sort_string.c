//26.   sort the input string

//  Ex: ip- helloworld               Op- dehllloorw

#include<stdio.h>
#include<string.h>
int main()
{
	int i,j;
	char ch[30],temp;
	printf("Enter the string:\n");
	scanf(" %s",ch);
	int s=strlen(ch);
	printf("string length:%d\n",s);
	for(i=0;i<s;i++)
	{
		for(j=i+1;j<s;j++)
		{
			if(ch[i]>ch[j])
			{
				temp=ch[j];
				ch[j]=ch[i];
				ch[i]=temp;
			}
		}
	}
	printf("The sortrd  string is:%s\n",ch);
}
