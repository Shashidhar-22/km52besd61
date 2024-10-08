/* 9	Write a program that opens a file with some number of characters written in it.
 An integer input is taken. If the input is positive, skip those many characters and print the remaining till end of the file. If the input is negative, then print those man y characters till end of the file.
eg., file contents :abcdefghijklmnopqrstuvwxyz
input number: 15, output: pqrstuvwxyz
input number: -10 , output: qrstuvwxyz */

#include<stdio.h>
int main()
{
	FILE *fp=NULL;
	int n;char ch;
	fp=fopen("alpha.txt","r+");
	if(fp==NULL)
	{
		printf("Error openinig:\n");
		return -9;
	}
	//fseek(fp,0,SEEK_END);
	//int size=ftell(fp)-1;
	//printf("size is :%d\n",size);
	printf("ENter number to print from alphabets:\n");
	scanf("%d",&n);
	if(n>=0)
	{
		fseek(fp,n,SEEK_CUR);
	}
	else //if(n<0) 
	{
		n-=1;
		fseek(fp,n,SEEK_END);

	}
	while(((ch=fgetc(fp))!=EOF))
	{
		printf("%c",ch);
	}
	fclose(fp);
	return 0;
}
