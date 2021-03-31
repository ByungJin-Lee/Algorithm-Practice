/*
	P_Name : "Snail Dreamming"
*/
#include <stdio.h>
#include <math.h>

int main(void){
	//Variables
	int vertical, day_move, night_move;
	//Work
	scanf("%d %d %d", &day_move, &night_move, &vertical);
	//Display
	printf("%d", (int)ceil(((double)vertical - night_move)/(day_move - night_move)));
	return 0;
}
