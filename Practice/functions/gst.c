#include<stdio.h>
void calprice(float value);   //declartion

	int main(){
	float value =100.0;
		calprice(value);
		printf("value is : %f\n",value);
	return 0;
	}

	void calprice(float value) {
	value = value+(0.18*value);
	printf("the final value is  : %f\n",value);
	}
