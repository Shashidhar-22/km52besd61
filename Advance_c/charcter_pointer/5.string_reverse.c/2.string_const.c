
#include<stdio.h>
#include<string.h>
char *mystrrev(const char*);
int main()
{
	char string[10];
	printf("Enter a string:");
	scanf("%s",string);
	char *revstr = mystrrev(string);
	printf("%s\n",revstr);
}
char *mystrrev(const char *string)
{
	char temp;
	int i,j;
	int s = strlen(string);
	for(i=0,j=s-1;i<s/2;i++,j--)
	{
		temp=string[i];
		string[i]=string[j];
		string[j]=temp;
	}
	return string;

}



/*output:
2.string_const.c: In function ‘mystrrev’:
2.string_const.c:21:26: error: assignment of read-only location ‘*(string + (sizetype)i)’
   21 |                 string[i]=string[j];
      |                          ^
2.string_const.c:22:26: error: assignment of read-only location ‘*(string + (sizetype)j)’
   22 |                 string[j]=temp;
      |                          ^
2.string_const.c:24:16: warning: return discards ‘const’ qualifier from pointer target type [-Wdiscarded-qualifiers]
   24 |         return string;
      |                ^~~~~~

*/
