#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int l;
int *sort2darray(int [],int [],int [],int ,int);
int main()
{
	int n,m,i,j,*arr,*a2,*a3;
	printf("Enter array sizes of 1 & 2:\n");
	scanf("%d%d",&n,&m);
	arr=(int *) malloc(n*sizeof(int));
	a2=(int *) malloc(m*sizeof(int));
	a3=(int *) malloc((n+m)*sizeof(int));
	printf("Enter first Array\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
		a3[i]=arr[i];
	}
	printf("Enter Second Array\n");
	for(j=0;j<m;i++,j++)
	{
		scanf("%d",&a2[j]);
		a3[i]=a2[j];
	}

	sort2darray(arr,a2,a3,n,m);

	for(i=0;i<l;i++)
		printf("%d ",a3[i]);
	printf("\n");
}
int *sort2darray(int arr[],int a2[],int a3[],int n,int m)
{
	int i,j,k;
	l=n+m;
	for(i=0;i<l;i++)
	{
		for(j=i+1;j<l;j++)
		{
			if(a3[i]==a3[j])
			{
				for(k=j;k<l-1;k++)
					a3[k]=a3[k+1];
				j--;
				l--;
			}
		}
	}

	for(i=0;i<l;i++)
	{
		for(j=i+1;j<l;j++)
		{
			if(a3[i]>a3[j])
			{
				int temp=a3[i];
				a3[i]=a3[j];
				a3[j]=temp;
			}
		}
	}

	return a3;
}
