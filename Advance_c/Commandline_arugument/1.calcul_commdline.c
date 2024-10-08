#include<stdio.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{

		if( argc!=4 )
	{
		printf("Invalid arguments\n");
		printf(" ./a.out <operand 1> < + , - '*' , % , / > <expression 2 >\n");}
	
	else
	{
	printf("you have entered %d arguments\n",argc);
	for (int i=0;i<argc;i++)
	{
		printf("%s\n",argv[i]);
	}
	int a=atoi(argv[1]);
	char *c=(argv[2]);
	int b=atoi(argv[3]);
	switch(*c){
		case '+':printf("%d\n",a+b);break;
		case '-':printf("%d\n",a-b);break;
		case '*':printf("%d\n",a*b);break;
		case '%':printf("%d\n",a%b);break;
		case '/':printf("%d\n",a/b);break;
		default:printf("Invaild operator\n");}
	}
	
       }
