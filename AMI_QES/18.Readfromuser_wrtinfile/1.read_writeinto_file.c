//18.   read lines of data and write in file.
#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *fp=NULL;
	char ch;
	fp=fopen("abc.text","w");
	if(fp==NULL)
	{
		printf("Error while open file:");
		return -99;
	}
	ch=getchar(); //get char is used to take input from keyboard
	while(ch!=EOF)
	{
		fputc(ch,fp);
		ch=getchar();
	}
	//fclose(fp);

	fp=fopen("abc.text","r");
	ch=fgetc(fp);
	while(ch!=EOF)
	{
		putchar(ch);
		ch=fgetc(fp);
	}
	printf(" %c",ch);
	fclose(fp);
	return 0;
}
