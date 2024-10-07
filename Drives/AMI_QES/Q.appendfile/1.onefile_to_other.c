
//24.    Append the contents of one file to other

#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *file1=NULL,*file2=NULL;
	char ch;
	file1=fopen("source.text","r");
	if(file1==NULL)
	{
		printf("file error opening:\n ");
		return -1;
	}
	file2=fopen("des.text","w");
	if(file2==NULL)
	{
		printf("file error opening:\n ");
		return -1;
	}
	while(((ch=fgetc(file1)))!=EOF)  //fgetc is copies content of fie1 and stored in ch (char)
	{
		fputc(ch,file2);	//fputc is used to copy content of ch and stored into file2
	}
	fclose(file1);
	fclose(file2);
	printf("Sucessfully copied\n");
	return 0;

}
