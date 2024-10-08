//3Read the contents of a file and copy to another file.
#include<stdio.h>
int main()
{
	FILE *fp1=NULL,*fp2=NULL;
	char ch;
	fp1=fopen("sor.txt","r");
	if(fp1==NULL)
	{
		printf("File error opening:\n");
		return -1;
	}
	fp2=fopen("des.txt","w");
	if(fp2==NULL)
	{
		printf("File opening error:\n");
		return -99;
	}
	while(((ch=fgetc(fp1)))!=EOF)
	{
		fputc(ch,fp2);
	}
	fclose(fp1);
	fclose(fp2);
	printf("Sucessfully copied:\n");
	return 0;
}

