/*
	P_Name : "Counting Number"
*/
#include <stdio.h>

int main(void){
	//Variables
	int multi = 1; //Result Multiple
	int numberTable[10] = {0}; //Table for count number
	//Work
	for(int i = 0, temp; i < 3; i++, multi *= temp) // Multiple
		scanf("%d", &temp); //Input Temp Value
	for(;multi >= 1; multi /= 10) //Make Table
		numberTable[multi % 10]++;
	for(int i = 0; i < 10; i++)
		printf("%d\n", numberTable[i]);
	return 0;
}
