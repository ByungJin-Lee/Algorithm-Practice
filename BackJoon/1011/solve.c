/*
	P_Name : "Fly me to the Alpha Centauri"
*/
#include <stdio.h>
#include <math.h>

int main(void){
	//Variabls
	int inputTestCase, start, end;	
	//Work
	scanf("%d", &inputTestCase);
	for(int i = inputTestCase, length, temp; i > 0; i--){
		scanf("%d%d", &start, &end);
		length = end - start;
		temp = (int)sqrt(length);
		if(temp*temp == length)
			printf("%d\n", 2*temp - 1);
		else if(length <= temp*temp + temp)
			printf("%d\n", 2*temp);
		else
			printf("%d\n", 2*temp + 1);
	}
	return 0;
}
