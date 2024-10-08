#include<stdio.h>
char *mysubstring(char c[],char n[]);
int main(){

	char c[100],n[100];
	scanf("%[^\n]s",c);
	scanf(" %s",n);


	printf("Adresss of matched string : %p",mysubstring(c,n));


	printf("\n");
}


char *mysubstring(char c[],char n[]){
	int i=0,j=0;

	printf("Base adress of the string : %p\n",c);

	while(*(c+i)){

		if(*(c+i)==*(n+j)){

			if(*(c+i+1)==*(n+j+1)){
				return (c+i);

			}

		}

		i++;

	}

}

