//21.   Count the number of words in a file.
#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *fptr=NULL;
	int wordcount=0;
	char ch;
	fptr=fopen("abc.txt","r");
	if(fptr==NULL)
	{
		printf("Error while opening a file:");
		exit(1);
	}
	while((ch=fgetc(fptr))!=EOF)
	{
		if((ch==' ' || ch=='\n'))
		{
			wordcount++;
		}
	}
	fclose(fptr);
	printf("total no of words in file is :%d\n",wordcount);
	return 0;
}
