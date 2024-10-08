#include<stdio.h>
char *mystrcat(char *des,char *sor);
int main()
{
        int s;
        char sor[50];
        char des[50];
        printf("Enter 1st string:" );
        scanf("%50[^\n]s",sor);
        printf("Enter 2nd string:");
        scanf(" %50[^\n]s",des);
       	char *d=mystrcat(des,sor);
       printf("%s\n",d);	
        return 0;
}

char *mystrcat(char *des,char *sor)
{

	int len=0,len1=0,i=0,j=0;
        while(*(des+i)!='\0')
	{
		len++;
		i++;
	}
	while(*(sor+j)!='\0')
	{
		len1++;
		j++;
	}

        for(i=0,j=len1;*(sor+i)!='\0' && i<len ;i++,j++)
	{
           *(des+j)=*(sor+i);
	}
       *(des+j)='\0';
       	return des;
}




