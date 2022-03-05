/*
	P_Name : "Sugar Deliver"
*/
#include <stdio.h>

int main(void){
	//Variables
	int inputSugar, count = 0;
	//Work
	scanf("%d", &inputSugar);
	while(inputSugar >= 0){
		if(inputSugar % 5 == 0) {
			printf("%d", inputSugar/5 + count);
			break;
		}
		inputSugar -= 3;
		count++;
		if(inputSugar < 0) printf("-1");
	}
}
