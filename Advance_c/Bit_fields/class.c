#include<stdio.h>
struct shashidhar
{
	int d:5;    //date start from 1-31 it takes 5 bits(16 8 4 2 1 => 1 1 1 1 1)
	int m:4;    //month start from 1-12 it takes 4 bits( 8 4 2 1 => 1 1 0 0)
	int y:20;    //year start from 2000-2100 it takes 20 bits()
};

int main()
{
	printf("%ld\n",sizeof(struct shashidhar));

}

