/*
	P_Name : "said Angle"
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
	//Variables
	int n_room, c_see_king, c_see_pown;
	unsigned long long min = 0;
	int *list_n_student;	
	//Input
	scanf("%d", &n_room);
	list_n_student = (int*)malloc(sizeof(int)*n_room);
	for (int i = 0, temp = 0; i < n_room; list_n_student[i++] = temp) scanf("%d", &temp);
	scanf("%d%d", &c_see_king, &c_see_pown);
	//Work
	for (int i = 0, r_temp = 0; i < n_room; i++, r_temp = 0){
		
		r_temp = list_n_student[i] - c_see_king;
		min++;
		if (r_temp <= 0) continue;
		min += (int)ceil(r_temp / (double)c_see_pown);
	}
	//Display - min
	printf("%llu", min);
	free(list_n_student);
	return 0;
}
