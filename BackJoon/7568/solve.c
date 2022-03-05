/*
	P_Name : "Weight"
*/
#include <stdio.h>

int main(void){
	int N, count, i;
	int weight[50], height[50];
	
	scanf("%d", &N);
	
	for(i = 0; i < N; i++)
		scanf("%d%d", &weight[i], &height[i]);
	
	for(i = 0; i < N; i++){
		count = 1;
		for(int j = 0; j < N; j++){
			if(j == i) continue;
			
			if(weight[i] < weight[j] && height[i] < height[j]){
				count++;
			}
		}
		printf("%d ", count);
	}
}
