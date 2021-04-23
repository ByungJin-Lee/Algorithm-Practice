/*
	P_Name : "Much Money"
*/
#include <stdio.h>
#define STAND 10000

int main(){
	char buffer[10001], buffer2[10001];
	unsigned short haveMoney[2501];
	unsigned short people[2501];
	int lenHaveMoney, lenPeople, i, j, out, range, temp, digit, result, sub, subRange, count = 0;	
	
	scanf("%s %s", buffer, buffer2);
	
	lenHaveMoney--; lenPeople--;
	sub = lenHaveMoney - lenPeople;
	
	for(lenHaveMoney = 0, out = 0, i = 0; out != 1; lenHaveMoney++){
		haveMoney[lenHaveMoney] = 0;
		for(i = lenHaveMoney*4, range = 0; range < 4 ; i++, range++){
			for(digit = 1, j = 3; j > range; j--){
				digit *= 10;
			}
			if((temp = buffer[i]) != 0){				
				haveMoney[lenHaveMoney] = haveMoney[lenHaveMoney] + (temp-48)*digit;
			}else{				
				for(j = range; j < 4; j++){
					haveMoney[lenHaveMoney] = haveMoney[lenHaveMoney] / (digit*10);
				}
				haveMoney[lenHaveMoney] = haveMoney[lenHaveMoney] + (STAND*(range+1));
				out = 1;
				break;
			}
		}
	}
	
	for(lenPeople = 0, out = 0, i = 0; out != 1; lenPeople++){
		people[lenPeople] = 0;
		for(i = lenPeople*4, range = 0; range < 4 ; i++, range++){
			for(digit = 1, j = 3; j > range; j--){
				digit *= 10;
			}
			if((temp = buffer2[i]) != 0){				
				people[lenPeople] = people[lenPeople] + (temp-48)*digit;
			}else{
				for(j = range; j < 4; j++){
					people[lenPeople] = people[lenPeople] / (digit*10);
				}
				people[lenPeople] = people[lenPeople] + (STAND*(range+1));
				out = 1;
				break;
			}
		}
	}				
		 	
	subRange = lenPeople - 1;
	
	printf("%d", haveMoney[sub+subRange - 1]);
	
	while(1){		
		temp = 0; result = 0;
		
		
		
		if(temp < 0) break;
	}
		
	printf("%d\n", count - 1);
	for(i = 0; i < lenHaveMoney - 1; i++)
		printf("%04d", haveMoney[i]);
	
}
