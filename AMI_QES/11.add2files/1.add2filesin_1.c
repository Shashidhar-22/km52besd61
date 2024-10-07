//11.   Create a new file using contents of two files.(append one file content to another, and write to a third file).

#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *file1=NULL,*file2=NULL,*file3=NULL;
	char ch1,ch2;
	file1=fopen("f1.text","r");
	if(file1==NULL)
	{
		printf("file error opening:\n ");
		return -1;
	}
	file2=fopen("f2.text","r");
	if(file2==NULL)
	{
		printf("file error opening:\n ");
		return -1;
	}

	file3=fopen("f3.text","w");
	if(file2==NULL)
	{
		printf("file error opening:\n ");
		return -1;
	}

	while(((ch1=fgetc(file1)))!=EOF)
	{
		fputc(ch1,file3);
	}
	while(((ch2=fgetc(file2)))!=EOF)
	{
		fputc(ch2,file3);
	}
	fclose(file1);
	fclose(file2);
	fclose(file3);
	printf("Sucessfully copied from two files\n");
	return 0;
}


