#include<stdio.h>
enum week{
	sun=12,mon,thu,wed,thrs,fri,sat
};

int main()
{

	for(int i=sun;i<=sat;i++)	
		printf("%d\t\n",i);
	return 0;

}
