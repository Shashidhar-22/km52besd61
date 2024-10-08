#include<string.h>
int mystrstr(char str[],char sub[]);
int main()
{
	char str[20]={"kernal"};
	char sub[20]={"er"};
	int x;
	x=mystrstr(str,sub);

	return 0;

}
int mystrstr(char str[],char sub[])
{
	int i,j,x,m,n,count=0;
	n=strlen(str);
	m=strlen(sub);
	j=m-1;
	for(i=n-1;i>=0;i--)
	{
		if(str[i]==sub[j])
		{
			count++;
			j--;
			if(count==m)
				return i;
		}
	}
}

