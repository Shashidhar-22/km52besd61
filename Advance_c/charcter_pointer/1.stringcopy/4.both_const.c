/* Implement your own string copy function.
try calling the string copy function by sending the below as input:
1) string constant as destination and string variable as source
2) string variable as destination and string constant as source
3) string variable as destination and string variable as source
4) string constant as destination and string constant as source
  note down the output and analyze the reasons.
*/



//4) string constant as destination and string constant as source

#include<stdio.h>
#include<string.h>
void mystrcpy( const char*,const char*);
int main()
{
	char str1[20],str2[20];
	printf("Enter string1:");
	scanf("%s",str1);
	printf("Enter string2");
	scanf("%s",str2);
	mystrcpy(str1,str2);
	printf("%s",str2);
	return 0;
}
void mystrcpy(const char* dest,const char* sorc)
{
	int i;
	for( i=0;sorc[i]!='\0';i++)
	{
		dest[i]=sorc[i];
	}
	dest[i]='\0';
}

/*

output:
4.both_const.c: In function ‘mystrcpy’:
4.both_const.c:33:32: error: assignment of read-only location ‘*(dest + (sizetype)i)’
33 |                         dest[i]=sorc[i];
|                                ^
4.both_const.c:35:24: error: assignment of read-only location ‘*(dest + (sizetype)i)’
35 |                 dest[i]='\0';
*/




