#include<stdio.h>
struct stu
{
int x;	int y;
};

int main()
{
	printf("size of struct tagname:%ld\n",sizeof(struct stu));
	return 0;
}

