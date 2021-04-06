/*
	P_Name : "For money"
*/
#include <stdio.h>
#include <stdlib.h>

int search(int *times, int *money, int start, int end){
	int result = 0;
	for(int i = start, left, right = 0; i < end; i++){		
		//If timeSchedule Value is equal "-1", then impossible Schedule
		if(times[i] == -1) continue;
		//if 1 then always work
		if(times[i] == 1){
			result += money[i];
			continue;
		}
		//Work
		//not 1 then Recursive
		//Start This
		left = search(times, money, i+times[i], end);
		//Start Another
		for(int j = i+1, size = i+times[i]-1, temp; j < size; j++){
			if((temp = search(times, money, j, end)) > right) right = temp;
		}
		//Compare
		result = result + (left > right) ? left:right;
	}
	return result;
}

int main(void){
	//Variables
	int count_set, count_not_contain = 0, totalMoney;
	int *timeSchedule, *workSchedule;
	
	//Input
	scanf("%d", &count_set);
	//0-create Dynamics Array
	timeSchedule = (int*)malloc(sizeof(int)*count_set);
	workSchedule = (int*)malloc(sizeof(int)*count_set);
	//0-Input Value
	for(int i = 0; i < count_set; scanf("%d%d", &timeSchedule[i], &workSchedule[i++]));
	
	//Work
	//0-Check Possible(if impossible time then save -1)
	for(int i = 0; i < count_set; timeSchedule[i] = (timeSchedule[i]+i > count_set)?-1:timeSchedule[i],i++);
	//1-Calculate
	totalMoney = search(timeSchedule, workSchedule, 0, count_set);	
	
	//Display
	printf("%d", totalMoney);
	
	//Free
	free(timeSchedule);
	free(workSchedule);
	return 0;
}
