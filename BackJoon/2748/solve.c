/*
	P_Name : "fibonacci 2"
*/
#include <stdio.h>
#include <stdlib.h>

long long fibonacci(int N){
	if(N == 0 || N == 1) return N;
	//N >= 2
	long long* list = (long long*)malloc(sizeof(long long)*N+1);
	list[0] = 0; list [1] = 1;
	for(int i = 2; i <= N; list[i] = list[i-1] + list[i-2], i++);
	long long r = list[N];
	free(list);
	return r;
}

int main(){
	//Variables
	long N;
	//Input
	scanf("%d",&N);
	//Work
	//Display	
	printf("%lld", fibonacci(N));
}
