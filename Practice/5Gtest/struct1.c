#include<stdio.h>
struct stu
{
	char *c;
	struct stu *point;
};

void main()
{
	struct stu s;
	//struct stu *m=&s;
	printf("size of struct variabe:%ld\n",sizeof(s));
	
}

