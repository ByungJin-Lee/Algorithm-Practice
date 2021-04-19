/*
	P_Name : "promise"
*/
#include <stdio.h>
#include <math.h>
int T[10000];
int Temp_T[10000];

void mergeSort(int s, int m, int l){
	int d_l = s, d_r = m + 1, d_i = s;
	//Sort
	while(d_l <= m && d_r <= l){
		if(T[d_l] < T[d_r])
			Temp_T[d_i++] = T[d_l++];
		else
			Temp_T[d_i++] = T[d_r++];
	}
	while(d_l <= m)
		Temp_T[d_i++] = T[d_l++];
	while(d_r <= l)
		Temp_T[d_i++] = T[d_r++];
	//adapt
	for(int i = s; i <= l; T[i] = Temp_T[i], i++);
}


void merge(int s, int l){
	//End Condition
	if(l <= s) return;
	int m = s + (l-s)/2;
	//merge
	merge(s, m); //-left
	merge(m+1, l); //-right
	//Sort
	mergeSort(s, m, l);
}

int main(void){
	//Variables
	int C;
	//Input
	scanf("%d", &C);
	if(C%2 == 1){
		printf("1");
		return 0;
	}
	for(int i = 0, s, a; i < C; i++){
		scanf("%d%d", &s, &a);
		T[i] = s - a;
	}
	//Work
	merge(0, C-1);
	//Display
	for(int i = 0; i < C; i++)
		printf("%d ", T[i]);	
	printf("%d", abs(T[C/2] - T[C/2 - 1]) + 1);
	return 0;
}
