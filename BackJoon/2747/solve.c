/*
	P_Name : "fibonacci Number"
*/
#include <stdio.h>
#include <stdlib.h>

int fibonacci(int N){
	//N >= 2
	int* list = (int*)malloc(sizeof(int)*N+1);
	list[0] = 0; list [1] = 1;
	for(int i = 2; i <= N; list[i] = list[i-1] + list[i-2], i++);
	int r = list[N];
	free(list);
	return r;
}

int main(){
	//Variables
	int N;
	//Input
	scanf("%d",&N);
	//Work
	//Display	
	printf("%d", fibonacci(N));
}
