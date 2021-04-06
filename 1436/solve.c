/*
	P_Name : "Movie Director, Shum"
*/
#include <stdio.h>
#include <stdbool.h>

int search(int number, int count, int next){
	bool isChain = false;
	int c = 0;
	while(number >= 1){
		if(number % 10 == next){
			if(!isChain) isChain = true;
			c++;
			if(c == count) return 1;
		}else{
			c = 0;
		}
		number /= 10;
	}
	return 0;
}

int main(void){
	//Variables
	int count, standard = 666;
	//Input
	scanf("%d", &count);
	//Work
	while(count > 0)
		if(search(standard++,3,6)) count--;
	//Display
	printf("%d", standard-1);
}
