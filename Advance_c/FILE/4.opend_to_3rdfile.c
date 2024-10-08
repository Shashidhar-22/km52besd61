/*4Create a new file using contents of two files.(append one file content to another, and write to a third file).*/

#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *fp1,*fp2,*fp3;
	char ch1,ch2;
	fp1=fopen("file1.txt","r");
	if(fp1==NULL)
	{
		printf("file opening error:");
		exit(0);
	}
	fp2=fopen("file2.txt","r");
	if(fp2==NULL)
	{
		printf("file opening error:");
		exit(0);
	}
	fp3=fopen("file3.txt","w");
	if(fp3==NULL)
	{
		printf("file opening error:");
		exit(0);
	}
	while(((ch1=fgetc(fp1)))!=EOF)
	{
		fputc(ch1,fp3);
	}

	while(((ch2=fgetc(fp2)))!=EOF)
	{
		fputc(ch2,fp3);
	}
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
	printf("sucessfully copied from 2 files:\n");
	return 0;
}
