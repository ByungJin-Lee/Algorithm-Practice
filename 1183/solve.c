/*
	P_Name : "promise"
*/
#include <stdio.h>
#include <stdlib.h>

int calcWait(int o, int deltaT, int a){
	int result = o + deltaT - a;
	return (result > 0) ? result : -1*result;
}

void merge(int *_array, int s, int mid, int l){		
	//Work
	int i_f = s, i_b = mid + 1, i_cur = 0;
	int *tempArray = (int*)malloc(sizeof(int)*(l-s));
	//-Case 3
	//--First
	while((i_f <= mid)&&(i_b <= l)){
		if(_array[i_f] <= _array[i_b]) tempArray[i_cur++] = _array[i_f++];
		else tempArray[i_cur++] = _array[i_b++]; 						
	}
	//--Second(right empty)
	while(i_f <= mid) tempArray[i_cur++] = _array[i_f++];
	//--Third(left empty)
	while(i_b <= l) tempArray[i_cur++] = _array[i_b++];
	//Merge
	i_cur--; i_b--;
	while(i_cur>=0) _array[i_b--] = tempArray[i_cur--];
	free(tempArray);
}
void mergeSort(int *_array, int s, int l){	
	if(l > s){
		//middle
		int mid = s + (l-s)/2;
		//Left
		mergeSort(_array, s, mid);
		//Merge
		mergeSort(_array, mid+1, l);
		//Calc
		merge(_array, s, mid, l);
	}
}

void displayTables(int *o, int *a, int *d, int size){
	printf("\n|=====|=====|=====|\n");
	printf("| ori | arr | del |\n");
	printf("|=====|=====|=====|\n");
	for(int i = 0; i < size; i++)
		printf("|%+5d|%+5d|%+5d|\n", o[i], a[i], d[i]);
	printf("|=====|=====|=====|\n");
}

int main(void){
	//Variables
	int T, count = 0;
	int *o_promises, *d_times, *c_table;
	//Input
	scanf("%d", &T);
	o_promises = (int*)malloc(sizeof(int)*T);
	d_times = (int*)malloc(sizeof(int)*T);
	c_table = (int*)malloc(sizeof(int)*T);
	for(int i = 0; i < T; i++){
		scanf("%d%d", &o_promises[i], &d_times[i]);
		c_table[i] = o_promises[i] - d_times[i];
	}
	//Work
	mergeSort(c_table,0, T);
	for(int i = 0, min = -1, temp = 0; i < T; i++, temp = 0){		
		while(i!= 0 && c_table[i] == c_table[i-1])i++;
		for(int j = 0, delta = c_table[i]; j < T; j++)
			temp += calcWait(o_promises[j], delta, d_times[i]);
		if(min == -1) min = temp;			
		if(min == temp) count++;
		else if(min > temp){
			min = temp;
			count = 1;
		}
	}	
	//Display
	printf("%d", count);
	//Free
	free(c_table);
	free(o_promises);
	free(d_times);
	return 0;
}
