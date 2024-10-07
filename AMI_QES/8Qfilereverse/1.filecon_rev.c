//8.      Read a file and print the file contents in reverse order.
//Ex: file contains 0,1,2,3…..100
//       Print  100,99,………..0

#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *fptr=NULL;
	int i=0,ft;
	fptr=fopen("shashi.txt","r");
	if(fptr==NULL)
	{
		printf("error while opening a file:");
		return -109;
	}
	fseek(fptr,0,SEEK_END);
	ft=ftell(fptr);
	while(i<ft)
	{
		i++;
		fseek(fptr,-i,SEEK_END);
		printf("%c",fgetc(fptr));
	}
	fclose(fptr);
	return 0;
}
