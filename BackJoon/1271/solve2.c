/*
	P_Name : "Much Money"
*/
#include <stdio.h>

int main(void){
	char haveMoney[10001];
	char amountPerson[10001];
	int lenHaveMoney = 0, lenAmountPerson = 0, sub, countDivisor = 0, isZero = 1, i, end = 0;
	
	scanf("%s %s", haveMoney, amountPerson);	

	while(haveMoney[lenHaveMoney++] != 0) {}
	while(amountPerson[lenAmountPerson++] != 0){}
	lenHaveMoney--; lenAmountPerson--;
	sub = lenHaveMoney - lenAmountPerson;					
	
	while(1){				
		for(i = 0; i < lenAmountPerson; i++){			
			haveMoney[sub+i] = haveMoney[sub+i] - amountPerson[i] + '0';
		}	
		for(i = lenHaveMoney - 1; i > 0; i--){		
			if(haveMoney[i] < '0'){
				haveMoney[i] += 10;
				haveMoney[i-1] -= 1;
			}
		}
		countDivisor++;
		//EndConditon
		for(int i = 0; i <= sub; i++){
			if(haveMoney[i] < '0'){
				end = 1;
				break;
			}
		}
		if(end){
			for(i = 0; i < lenAmountPerson; i++){			
				haveMoney[sub+i] = haveMoney[sub+i] + (amountPerson[i] - '0');
			}
			for(i = lenHaveMoney - 1; i > 0; i--){		
				if(haveMoney[i] > '9'){
					haveMoney[i] = haveMoney[i] - 10;
					haveMoney[i-1] = haveMoney[i-1] + 1;
				}		
			}
			break;	
		}
	}	
	printf("%d\n", countDivisor-1);
	for(i = 0; i < lenHaveMoney; i++){
		if(haveMoney[i] != '0'){
			isZero = 0;
		}
		if(!isZero){
			printf("%c", haveMoney[i]);
		}
	}
	if(isZero) printf("0");
	return 0;
}
