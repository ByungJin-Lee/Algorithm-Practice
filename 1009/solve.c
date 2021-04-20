/*
	P_Name : "Disperse process" 
*/
#include <stdio.h>

int main(void){
	//Variables
	int T;
	int table[8][4] = {
		{6,2,4,8},
		{1,3,9,7},
		{6,4,6,4},
		{5,5,5,5},
		{6,6,6,6},
		{1,7,9,3},
		{6,8,4,2},
		{1,9,1,9},		
	};
	//Input
	scanf("%d", &T);
	//Work
	for(int i = 0, a, b, r; i < T; i++){
		scanf("%d%d", &a,&b);
		a %= 10;
		if(a == 1){
			printf("1\n");
			continue;
		}else if(a == 0){
			printf("10\n");
			continue;
		}
		b %= 4;
		printf("%d\n", table[a-2][b]);
	}	
	return 0;
}
