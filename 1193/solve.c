/*
	P_Name : "Find! Fraction"
*/
#include <stdio.h>

int main(void){
	//Variables
	int input, n = 1, delta;
	//Input
	scanf("%d", &input);
	//Work
	while(input > (delta=(n+2)*(n-1)/2 + 1)) n++;
	delta = delta - input;
	//Display
	if(n % 2 == 1)
		printf("%d/%d", 1+delta, n-delta);
	else
		printf("%d/%d", n-delta, 1+delta);
	return 0;
}
