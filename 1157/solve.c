/*
	P_Name : "Counting Work"
*/
#include <stdio.h>
#include <stdbool.h>

int main(void){
	//Variables
	char buffer[1000000];
	bool wordReady = false;
	int w_count = 0;
	//Work
	scanf("%[^\n]", buffer);
	int index = 0; char temp;
	while((temp = buffer[index++]) != 0){
		if(!wordReady && temp != ' ') wordReady = true;
		if(wordReady && (temp == ' ' || buffer[index] == 0)) w_count++;
	}
	//Display
	printf("%d", w_count);
	return 0;
}
