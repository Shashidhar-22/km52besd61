//1.keep reading numbers from user, and write those numbers to a file. Once user presses -1, stop reading, and print all the contents of the file. Open the file everytime with previous contents intact (append mode).

#include <stdio.h>
int main() {
	FILE *fp = NULL;
	int n;
	fp=fopen("xyz.txt","a+");
	if(fp==NULL)
	{
		printf("Error while open:");
		return -9;
	}
	printf("Enter numbers:ENter -1 to stop reading:");
	while(1)
	{
		scanf("%d",&n);
		if(n==-1)
			break;
		fprintf(fp, "%d" ,n);
	}
	rewind(fp);
	printf("Contents of file:");
	while(fscanf(fp,"%d",&n)!=EOF)
	{
		printf("%d " ,n);
	}
	printf("\n");
	fclose(fp);
	return 0;
}

