#include"upcase.h"
#define n 5
struct student s[n];
void fun(struct student s[]);
int main()
{
	int i;
	for(i=0;i<n;i++){
		printf("Enter the names:");
		scanf(" %[^\n]s",s[i].name);}
	fun(s);
	printf("\n");
	printf("The uppercase names are:\n");
	for(int j=0;j<n;j++){
		printf(" %s\n",s[j].name);
	}

}

void fun(struct student s[])
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;s[i].name[j]!=0;j++)
		{
			if(s[i].name[j] >= 'a' && s[i].name[j] <= 'z')
				s[i].name[j] = s[i].name[j]-32;
		}
	}
}

