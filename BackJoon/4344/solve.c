/*
	P_Name: "I think I will be over average..."
*/
#include <stdio.h>
#include <stdlib.h>
int main(void){
	//Variables
	int t_number; //Test Case Number
	double *overAverage; //Dynamics Double Array For over Average
	int subCase[1000];
	//Work
	scanf("%d", &t_number);
	overAverage = (double*)malloc(sizeof(double)*t_number); //Create Dynamics Array
	for(int i = 0, sub = 0, size = 0; i < t_number; i++){
		double avg = 0;
		scanf("%d", &sub); //Input Sub Case
		size = sub; //Save subSize at size
		while(sub-- > 0){
			scanf("%d", &subCase[sub]); //Input Value
			avg += subCase[sub]; //Sum			
		}
		avg = avg/size; sub = size; //Calculate Average and init sub
		int count = 0; //Counting student over Average		
		while(sub-- > 0){
			if(subCase[sub] > avg)
				count++; 
		}			
		overAverage[i] = (double)count / size;//Calculate
	}	
	//Display
	for(int i = 0; i < t_number; i++)
		printf("%.3lf%%\n", overAverage[i] * 100);
	return 0;
}
