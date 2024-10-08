/*13 WAP to take an input string from the user, and delete the given word n number of times from a file.
  Eg., input : world , 5
  Find and delete the word “world” in a file 5 times.*/

#include <stdio.h>
#include <string.h>
int main()
{
	FILE *fp=fopen("shashi.txt","r+");
	if(fp==NULL)
		printf("open fail");
	else
	{
		char s[10],c,t[10];
		int i,j,n,k=0;
		printf("enter a word\n");
		scanf("%s",s);
		printf("no.of times:");
		scanf("%d",&n);
		while(n)
		{
			for(i=k,j=0;((t[j]=fgetc(fp))!=' ');i++,k++,j++);
			k++;
			t[j]='\0';
			if(strcmp(s,t)==0)
			{
				fseek(fp,-(strlen(t)+1),SEEK_CUR);
				for(int i=0;i<strlen(s);i++)
					fputc(' ',fp);
				n--;
			}
		}
		fclose(fp);
	}
}
