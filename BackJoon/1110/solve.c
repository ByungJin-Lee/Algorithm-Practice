/*
	P_Name : "Plus Cycle"
*/
#include <stdio.h>

int main(void){
	//Variables
	int inputV, save, count = 0;
	//Work
	scanf("%d", &inputV);
	save = inputV;
	do{
		inputV = (inputV%10)*10 + ((inputV/10)+(inputV%10))%10;
		count++;
	}while(inputV != save);
	//Display
	printf("%d", count);
	return 0;
}

