/*
	P_Name : "Break Even Point"
*/
#include <stdio.h>

int main(void){
	//Variables
	int fixed_cost, vari_cost, benefit;	
	//Work
	scanf("%d %d %d", &fixed_cost, &vari_cost, &benefit);
	//Display
	if(vari_cost >= benefit) printf("-1");
	else printf("%d", fixed_cost/(benefit - vari_cost) + 1);
	return 0;
}
