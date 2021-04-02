/*
	P_Name : "Sum and div"
*/
#include <stdio.h>

int main(void){
	//Variables
	int inputV, copyV, range, result = 0;
	int digit = 1;
	//Input
	scanf("%d", &inputV);
	copyV = inputV;
	//Work
	//Counting Digits
	while ((copyV /= 10) >= 1) digit++;
	//Check Range
	range = digit * 9;	
	//Check Value
	for (int i = inputV - range, sum = 0; i < inputV; i++, sum = 0){	
		if (i < 2) continue;
		copyV = i;
		while (copyV >= 1){
			sum += copyV % 10;
			copyV /= 10;
		}
		//Exit
		if (inputV == i + sum) {
			result = i;
			break;
		}
	}
	//Display
	printf("%d", result);
	return 0;
}
