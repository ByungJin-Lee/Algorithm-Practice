/*
	P_Name : "said Angle"
*/
#include <stdio.h>
#include <stdlib.h>

int main(void){
	//Variables
	int n_room;
	int *list_n_student;
	int c_see_king, c_see_pown;
	//Input
	scanf("%d", &n_room);
	list_n_student = (int*)malloc(sizeof(int)*n_room);
	for(int i = 0, temp = 0; i < n_room; list_n_student[i++] = temp) scanf("%d", &temp);
	scanf("%d%d", &c_see_king, &c_see_pown);
	//Work
	
	//Display - min
	printf("%d");
	return 0;
}
