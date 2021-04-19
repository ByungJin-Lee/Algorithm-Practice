/*
	P_Name : "Dice"
*/
#include <stdio.h>
#include <stdarg.h>

int DICE[6];

int get_two_pair(int args, ...){
	va_list ap;
	va_start(ap, args);
	int first = va_arg(ap, int); 
	int prev = first, prevSum = -1;	
	for(int i = 1, temp; i < args; i++){
		temp = va_arg(ap, int);
		if(prevSum == -1 || prevSum > prev + temp)
			prevSum = prev + temp;
		prev = temp;
	}
	if(prevSum > first + prev)
		prevSum = first + prev;
	va_end(ap);
	return prevSum;
}

int min(int args, ...){
	va_list ap;
	va_start(ap, args);
	int min = va_arg(ap, int);
	for(int i = 1, temp; i < args; i++){
		temp = va_arg(ap,int);
		if(min > temp) min = temp;
	}
	return min;
}

int max(int args, ...){
	va_list ap;
	va_start(ap, args);
	int max = va_arg(ap, int);
	for(int i = 1, temp; i < args; i++){
		temp = va_arg(ap,int);
		if(max < temp) max = temp;
	}
	return max;
}

int get_three_pair(){
	//select Center
	int lower = min(2, DICE[2], DICE[3]);
	//get Lower 2 pair
	int pair = get_two_pair(4, DICE[4], DICE[0], DICE[1], DICE[5]);
	//return
	return lower + pair;
}

int get_pair(){
	int lower = min(2, DICE[2], DICE[3]);
	int r1 = lower + min(4, DICE[4], DICE[0], DICE[1], DICE[5]);
	int r2 = get_two_pair(4, DICE[4], DICE[0], DICE[1], DICE[5]);
	if(r1 > r2) return r2;
	else return r1;
}

int main(){
	//Variable
	unsigned long long N;
	//Input
	scanf("%llu", &N);
	//-side
	for(int i = 0; i < 6; scanf("%d", &DICE[i++]));
	//Work
	int s3 = get_three_pair();
	int s2 = get_pair();
	int s1 = min(6, DICE[0],DICE[1],DICE[2],DICE[3],DICE[4],DICE[5]);
	//Display
	unsigned long long r = 0;
	if (N == 1)
		r = DICE[0] + DICE[1] + DICE[2] + DICE[3] + DICE[4] + DICE[5] - max(6, DICE[0],DICE[1],DICE[2],DICE[3],DICE[4],DICE[5]);
	else if(N == 2)
		r = s3 * 4 + s2 *4;
	else 
		r = s3 * 4 + s1 * ((N-1)*(N-2)*4 + (N-2)*(N-2)) + s2 * ((N-1)*4 + (N-2)*4);
	printf("%llu", r);
	return 0;	
}
