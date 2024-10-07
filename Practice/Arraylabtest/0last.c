#include<stdio.h>
#define MAX 5
#define INC if(arr[i]>arr[i+1]){temp=arr[i+1];arr[i+1]=arr[i];arr[i]=temp;}
#define ZERO if(arr[i]==0){temp=arr[i+1];arr[i+1]=arr[i];arr[i]=temp;}
int main()
{
	int arr[MAX];
	int i,j,temp;
	printf("Enter arry Elements:\n");
	for(i=0;i<MAX;i++)
	scanf("%d",&arr[i]);
	printf("Entered array elements are:");
	for(i=0;i<MAX;i++)
		printf("%d",arr[i]);
	printf("\n");
	for(j=0;j<MAX;j++){
		for(i=0;i<MAX;i++){
/*	if(arr[i]>arr[i+1]){
		temp=arr[i+1];
		arr[i+1]=arr[i];
		arr[i]=temp;
	}  */
		INC;
		}
	}
	printf("Incresing order is:");
	for(i=0;i<MAX;i++)
		printf("%d",arr[i+1]);

		printf("\n");
		for(j=0;j<MAX;j++){
		for(i=0;i<MAX;i++){
			ZERO;
		}
		}
		printf("Zeros at last is:");
		for(i=0;i<MAX;i++)
		printf("%d",arr[i]);
		printf("\n");
}




