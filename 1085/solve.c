/*
	P_Name : "Calculate the shortest Length"
*/
#include <stdio.h>

int main(void){
	//Variables [x, y, width, heigth]
	int positions[4], min;
	//Input
	for(int i = 0; i < 4; scanf("%d", &positions[i++]));
	min = positions[0];
	//Work
	for(int i = 1, result; i < 4; i++, min = (min > result) ? result : min){
		if(i == 2 || i == 3) result = positions[i] - positions[i-2];
		else result = positions[i];		
	}
	//Display
	printf("%d", min);	
	return 0;
}
