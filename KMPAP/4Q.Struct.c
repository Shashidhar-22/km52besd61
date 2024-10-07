#include<stdio.h>
struct stu
{
	int x;
	struct bag
	{
		int y;
	}    //su; //if variable is declared sie is 8
}s;
int main()
{
	printf("size is :%ld\n",sizeof(struct stu));
	printf("size is :%ld\n",sizeof(s));
	return 0;
}
