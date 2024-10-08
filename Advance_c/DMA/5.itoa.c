
#include<stdio.h>
#include<stdlib.h>
char *myitoa(int a,int n)
{
	int i=0;
	char *str=(char *)malloc(n*sizeof(char));
	while(a>0)
	{
		str[i] = 48+(a%10);
		a /= 10;
		i++;
	}
	return str;
}

int main()
{
	int a,i,n;
	printf("Enter the size of the string : ");
	scanf("%d",&n); 
	char *p = (char *)malloc(n*sizeof(char));
	printf("Enter the integer : ");
	scanf("%d",&a);
	p= myitoa(a,n);
	for(i=sizeof(p);i>=0;i--)
	{
		printf("%c",p[i]);
	}
	printf("\n");
}

