/*
	P_Name : "Big!!! Number"
*/
#include <stdio.h>
#include <stdlib.h>

#define INPUT_SIZE 1000

int main(void){
	//Variables
	char *nBuffer_1 = NULL, *nBuffer_2 = NULL;
	int length_1 = 0, length_2 = 0, max, sub;
	int *result;
	//init
	nBuffer_1 = (char*)malloc(sizeof(char)*INPUT_SIZE);
	nBuffer_2 = (char*)malloc(sizeof(char)*INPUT_SIZE);
	//Input
	scanf("%s %s", nBuffer_1, nBuffer_2);
	//Work
	//Count - length
	while (nBuffer_1[length_1] != 0) length_1++;
	while (nBuffer_2[length_2] != 0) length_2++;
	//Compare
	if (length_1 >= length_2) {
		max = length_1; sub = max - length_2;
	}
	else{
		max = length_2; sub = max - length_1;
		//change postion
		char *temp = nBuffer_1; nBuffer_1 = nBuffer_2; nBuffer_2 = temp;
	}
	result = (int*)malloc(sizeof(int)*max + 1); //Plus One digit
	//init
	for (int i = 0; i<= max; result[i++] = -1);
	//Input value
	for (int i = max-1; i >= sub; i--)
		result[i+1] = (int)((nBuffer_1[i] - '0') + (nBuffer_2[i - sub] - '0'));
	for (int i = 0; i < sub; i++)
		result[i + 1] = (int)(nBuffer_1[i] - '0');
	//Calculate
	for (int i = max; i > 0; i--){
		if (result[i] >= 10){
			result[i] -= 10;
			if (result[i - 1] == -1) result[i - 1] = 1;
			else result[i - 1]++;
		}
	}
	//Display
	for (int i = 0; i <= max; i++)
		if (result[i] != -1) printf("%d", result[i]);
}
