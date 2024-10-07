#include<stdio.h>
int main()
{
//	char str1[]="deep";
	char str2[]={'d','e','e','p','\0'};
	char str1[]="deep";
	if (str1==str2)
		printf("same");
	else
		printf("different");
}

