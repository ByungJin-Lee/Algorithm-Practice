/*
	P_Name : "Friend!"
*/
#include <stdio.h>
#include <stdbool.h>

bool peer[50][50] = {0,};
bool check2F[50][50] = {0,};

int main(){
	//Variables
	int N;
	char input[51];
	//Input
	scanf("%d", &N);
	for(int i = 0, j = 0; i < N; i++, j = 0){		
		scanf("%s", &input);
		while(input[j] != 0){
			peer[i][j] = (input[j] == 'Y')?true:false;
			j++;
		} 
	}
	//Work
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			//No loop
			if(i == j) continue;
			//Check			
			if(peer[i][j]){
				check2F[i][j] = true;
				for(int k = 0; k < N; k++){
					if(i == k || j == k) continue;
					//Check
					if(peer[j][k])
						check2F[i][k] = true;
				}				
			}	
		}		
	}
	//counting
	int max = 0;
	for(int i = 0, sum = 0; i < N; i++, sum = 0){
		for(int j = 0; j < N; j++)
			if(check2F[i][j]) sum++;
		max = (sum > max) ? sum : max;		
	}
	//Display
	printf("%d", max);
}
