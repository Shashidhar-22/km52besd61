/*6Write a program that compares two files and returns 0 if they are equal and 1 if they are not equal.*/

#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *fp1,*fp2;
	char c1,c2;
	fp1=fopen("f1.txt","r");
	if(fp1==NULL)
	{
		printf("open file1 fail:\n");
		exit(0);
	}
	fp2=fopen("f2.txt","r");
	if(fp2==NULL)
	{
		printf("open file 2 fail:\n");
		exit(0);
	}
	while(((c1=fgetc(fp1))!=EOF))
	{
		c2=fgetc(fp2);
		if(c1!=c2)
		{
			printf("both files are not same:1\n");
			return 1;
		}
	}
	fclose(fp1);
	fclose(fp2);
	printf("both files are same:0\n");
	return 0;
}

