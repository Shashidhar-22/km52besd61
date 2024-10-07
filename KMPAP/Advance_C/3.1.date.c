#include<stdio.h>
int main()
{
	int d,m,y;
	char *month[]={"null","January","febrary","March","April","May","June","July","Augest","September","December"};
	printf("ENter DOB :\n");
	scanf("%d%*c%d%*c%d",&d,&m,&y);
	switch(d)
	{
		case 1:
		case 21:
		case 31:
			printf("%dst ",d);break;
		case 2:
		case 22:
			printf("%dnd ",d);break;
		case 3:
		case 23:
			printf("%drd ",d);break;
		case 4 ... 20:
			printf("%dth ",d);break;
		case 24 ... 30:
			printf("%dth ",d);break;
	}
	printf("%s ",month[m]);
	printf("%d",y);
	printf("\n");
	return 0;
}

