/*
	P_Name : "Find Big about revered Number"
*/
#include <stdio.h>
int reverse(int number);

int main(void){
	//Variable
	int inputV1, inputV2;
	//Work
	scanf("%d %d", &inputV1, &inputV2);
	for(int i = 10; i <= 1000; i = i*10){
		if(inputV1 % i != inputV2 % i){
			printf("%d", (inputV1 % i > inputV2 % i) ? reverse(inputV1):reverse(inputV2));
			break;
		}
		else{
			continue;
		}
	}
}

int reverse(int number){
	int reversed = 0;
	while(number >= 1){
		reversed = 10*reversed + number % 10;
		number = number / 10;
	}
	return reversed;
}
