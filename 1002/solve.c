/*
	P_Name : "Terr~"
*/
#include <stdio.h>

int sqr(long long _number){
	return _number*_number;
}

void SWAP(long long *first, long long *second){
	for(int i = 0, temp; i < 3; i++){
		temp = first[i];
		first[i] = second[i];
		second[i] = temp;
	}
}

int main(void){
	//Variables[a,b,radius]
	long long circle_one[3], circle_two[3], interval, sumLength,subLength, count;
	//Input
	scanf("%d", &count);
	for(int k = 0; k < count; k++){		
		while(getchar() != '\n') { }
			//Input - circle one
		for(int i = 0; i < 3; scanf("%d", &circle_one[i++]));
			//Input - circle one
		for(int i = 0; i < 3; scanf("%d", &circle_two[i++]));	
		//Work
		if(circle_one[2] > circle_two[2]) SWAP(circle_one, circle_two);
		interval = sqr(circle_one[0] - circle_two[0])+sqr(circle_one[1] - circle_two[1]);
		sumLength = sqr(circle_one[2] + circle_two[2]);
		subLength = sqr(circle_two[2] - circle_one[2]);
		//Display
		//Result - 0
		if(interval < sumLength && interval > subLength) printf("2");
		else if(interval == sumLength || (interval == subLength && interval != 0)) printf("1");
		else if(interval < subLength || interval > sumLength) printf("0");
		else if(interval == 0){
			if(subLength == 0) printf("-1");
			else printf("0");
		}
		printf("\n");
	}
	return 0;
}
