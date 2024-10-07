#include<stdio.h>
#include<string.h>
int main()
{
	char *tens[] = {"\0","\0","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
	char *ones[] = {"\0","one","two","three","four","five","six","seven","eight","nine"};
    char *teens[] = {"ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","ninteen"};
	int num,i,j,rev=0,rem,c=0;
	printf("Enter the number : ");
	scanf("%d",&num); // 1234

	while(num>0)
	{
		rem = num%10;  // 1234%10 -> 4   123%10 --> 3  12%10 --> 2  1%10--> 1
		rev = rev * 10 + rem; // 0+4=4  4*10+3 = 43    43*10+2 = 432  432*10+1 = 4321
		num /= 10; // 1234/10--> 123   123/10 == > 12  12/10 ==> 1   1/10 = 0
		c++; // c = 1, c=2 , c=3, *c=4*
	}   // 1234 --> 4321

	if(c > 4)
	{
		printf("The limit is till thousands  only ! \n");
		goto label;
	}
	if(c==4)
		goto THSND;
	else if(c==3)
		goto HNDRD;
	else if(c==2)
	{
      goto TENS;
	}
	else if(c==1)
		goto ONES;


THSND:      j = rev%10;       
	    if(j>0 && j<10)
	    {
		    printf("%s thousand ",ones[j]);   
	    }
	    rev /= 10;  
HNDRD:      j= rev%10;   
	    if( j>0 && j<10)
	    {
		    printf("%s hundred ",ones[j]);  
	    }
	    rev /= 10;   

TENS:     j = rev%10;  
          if(j==0)
		  {
			j = rev/10;
			if(j>0 && j<10)
			  printf("%s ",ones[j]);
			  goto label;
		  }
		   j = rev%10;
           if(j==1)
          {  
            j = rev/10;   
            if(j>=0 && j<10)
              printf("%s ",teens[j]);  
            goto label;
          } 
            j = rev%10;   
	        if(j>0 && j<10)
	         {
		       printf("%s ",tens[j]);  
	         }
	        rev /= 10;  
ONES:      j= rev%10;  
	       if(j>0 && j<10)
	        {
		       printf("%s\n",ones[j]);  
	        }
label: return 0;	   
}