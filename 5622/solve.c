/*
	P_Name : "Dialog"
*/
#include <stdio.h>

int main(void){
	//Variabls
	char buffer[16], temp;
	int totalTime = 0, index = 0;
	//Work
	scanf("%s", buffer);
	while((temp = buffer[index++])!= 0){
		if(temp >= 'W') totalTime += 10;
		else if(temp >= 'T') totalTime +=9;
		else if(temp >= 'P') totalTime +=8;
		else if(temp >= 'M') totalTime +=7;
		else if(temp >= 'J') totalTime +=6;
		else if(temp >= 'G') totalTime +=5;
		else if(temp >= 'D') totalTime +=4;
		else if(temp >= 'A') totalTime +=3;
	}
	//Display
	printf("%d", totalTime);
	return 0;
}
