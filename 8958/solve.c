/*
	P_Name: "OX Quiz"
*/
#include <stdio.h>
#include <stdlib.h>

int main(void){
	//Variables
	int number; //Total OX Quizs
	int *score; //Dynamics Array
	char buffer[80]; //String	
	//Work
	scanf("%d", &number); //Input total
	score = (int*)malloc(sizeof(int)*number); //Create Array	
	for(int i = 0, j = 0, _s = 0; i < number; i++, j = 0, _s = 0){
		while(getchar() != '\n'); //Clear Input Buffer(Don't user fflush)
		scanf("%s", buffer);//Get Quiz Answer
		while(buffer[j] != 0){ //Character is not NULL Char			
			int delta = 1; //Score Plus
			while(buffer[j++] == 'O')
				_s += delta++;											
			if(delta != 1) j--; //Control Indel value
		}
		score[i] = _s; //Save score
	}
	//Display Result	
	for(int i = 0; i < number; i++)
		printf("%d\n", score[i]);
	return 0;
}
