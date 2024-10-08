#include<stdio.h>
//#include<string.h>
int mystrcmp(char *str1,char *str2,int n);
int main()
{
        int s,n;
        char str1[50];
        char str2[50];
        printf("Enter 1st string:" );
        scanf("%50[^\n]s",str1);
        printf("Enter 2nd string:");
        scanf(" %50[^\n]s",str2);
	printf("Enter count");
	scanf("%d",&n);
        s=mystrcmp(str1,str2,n);
        if (s==0)
                printf("Both are strings are same\n");
         if(s<0)
                printf("First is smaller then second\n");
         if (s>0)
                printf("First is bigger then second\n");
        return 0;
}

int mystrcmp(char *str1,char *str2,int n)
{
        int i;
        for(i=0;i<n;i++)
        {
                if (*(str1+i)!=*(str2+i))
                        return (*(str1+i)-*(str2+i));
                        }
        return 0;


}
