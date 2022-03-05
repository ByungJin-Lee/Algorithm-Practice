/*
	P_Name : "For money"
*/
#include <stdio.h>
#include <stdlib.h>

int search(int *times, int *money, int s, int end){		
	//End Condition
	int sum = 0, left = 0, right = 0;
	//If timeSchedule Value is equal "-1", then impossible Schedule		
	//if 1 then always work
	while(s < end && times[s] == 1) sum = sum + money[s++];		
	while(s < end && times[s] == -1 ) s++;
	if(s>=end) return sum;
	//Work
	//-choose 2 case
	//--choose this
	left = money[s] + search(times, money, s + times[s], end);			
	//--chose next		
	for(int i = s + 1, temp; i < times[s] + s; i++)
		if((temp = search(times, money, i, end)) > right) right = temp;
	//-calc result
	if(left > right) sum+=left;
	else sum+=right;
	return sum;
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
	for(int i = 0; i < count_set; scanf("%d%d", &timeSchedule[i], &workSchedule[i]),i++);	
	//Work
	//Check Table
	//0-Check Possible(if impossible time then save -1)
	for(int i = 0; i < count_set; timeSchedule[i] = (timeSchedule[i]+i > count_set)?-1:timeSchedule[i],i++);		
	//Display
	printf("%d", search(timeSchedule, workSchedule, 0, count_set));	
	//Free
	free(timeSchedule);
	free(workSchedule);
	return 0;
}
