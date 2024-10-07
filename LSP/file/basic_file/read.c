#include<unistd.h>
#include<stdio.h>
int main()

{
	char buff[100];
	int  ret;

	ret=read(0,buff,6);
		if(ret==0)
			printf("End of the file\n");
		else if (ret == 6)
			printf("6 bytes Read:%s\n",buff);


return 0;
}
