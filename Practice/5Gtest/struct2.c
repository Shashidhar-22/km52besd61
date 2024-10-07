#include<stdio.h>
struct stu
{
	char *c;
	struct stu *point;
};

void main()
{
	struct stu s;
	struct stu *m=&s;
	printf("size of struct variabe:%ld\n",sizeof(stu));//stu is tag name it is not possibe so error
	
}

