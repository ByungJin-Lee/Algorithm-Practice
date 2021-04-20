/*
	P_Name : "Goldbar's guess"
*/
#include <stdio.h>
#include <math.h>

int main(){
	//Variables
	int sum, status;
	//Input & work
	while(1){
		//Input Even Number
		scanf("%d", &sum);
		//EndCondition
		if(sum == 0) break;
		//Work - Only Old Number, prime
		for(int i = 3, op, size = sum/2; i <= size; i += 2, status = 2){
			status = 0;
			//Check prime
			for(int j = 2, j_size = sqrt(i); j <= j_size; j++){
				//End Condition
				if(i != j && i % j == 0) {
					status = 1; break; 
				}
			}
			//If not prime then next
			if(status) continue;
			//Find oppsite
			op = sum - i;
			//Check prime
			for(int j = 2, j_size = sqrt(op); j <= j_size; j++){
				//End Condition
				if(op != j && op % j == 0) {
					status = 1; break; 
				}
			}
			//If not prime then next
			if(status) continue;
			//This is Anwser! - End condition
			printf("%d = %d + %d\n", sum, i, op);
			break;
		}			
		if(status == 2) printf("Goldbach\'s conjecture is wrong.\n");
	}
	return 0;
}
