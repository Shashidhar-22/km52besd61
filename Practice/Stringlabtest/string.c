#include<stdio.h>
#include<string.h>
void rev(char str[]);
int main()
{
	int i,j;
	char str[50];
	char temp[50];
	printf("Enter the sentence:");
	scanf("%[^\n]s",str);
	rev(str);
		int len =strlen(str);
		for( i=0,j=4;i<=len/2;i++,j--)
		temp[i]=str[i];
		printf("%c",temp[i]);
}
void rev(char str[])
{
	int i,j,count=0;
	int len=strlen(str);
	char temp[50];
	for(int i=len-1;i>=0;i--)
		printf("%c",str[i]);
		count++;
		printf("%c",count);
}
/*
	
	for (int i=0,j=5;i<=len/2;i++,j--)	
		temp[i]=str[i];
		printf("%c",temp[i]);
	
	
	for(int i=6,j=7;i<=7;i++,j--)
		temp[i]=str[i];
	printf("%c",temp[i]);
			for(int i=9,j=16;i<=12;i++,j--)
			temp[i]=str[i];
			printf("%
			c",temp[i]);
				for(int i=18,j=21;i<=20;i++,j--)
				temp[i]=str[i];
				printf("%c",temp[i]);
				for(int i=23,j=24;i<=23;i++,j--)
				temp[i]=str[i];
				printf("%c" ,temp[i]);
				for (int i=26,j=30;i<=27;i++,j--)
				temp[i]=str[i];
				printf("%c",temp[i]);

				}
				*/

