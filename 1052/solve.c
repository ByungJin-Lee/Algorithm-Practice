/*
	P_Name : "Water Bottle"
*/
#include <stdio.h>

int main(void){
	//Variables
	int N, K;
	//Input
	scanf("%d%d", &N,&K);	
	//Work
	if(N <= K){
		printf("0");
		return 0;
	}
	int tN = N, count = 0, k_count = 0;
	while(1){
		while(tN){
			if(tN % 2) count++;
			tN /= 2;
		}				
		if(count <= K) break;
		tN = N + ++k_count;		
		count = 0;
	}
	printf("%d", k_count);
}
