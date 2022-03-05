/*
	P_Name : "Much Money"
*/
#include <stdio.h>

void straightenOutNumber(char *number, int len){	
	for(int i = len - 1; i > 0; i--){		
		if(number[i] < '0'){
			number[i] += 10;
			number[i-1] -= 1;
		}		
	}			
}

int minus(char *operand, char *oppsite, int lenOppsite, int sub){
	int mustBig = 0;
	
	for(int i = lenOppsite - 1; i >= 0; i--){
		if(operand[i+sub] < oppsite[i])
			mustBig = 1;
		if(operand[i+sub] > oppsite[i])
			mustBig = 0;
	}
	
	for(int i = 0; i < sub; i++){
		if(operand[i] > '0'){
			mustBig = 0;
			break;
		}			
	}
	
	if(!mustBig){
		for(int i = 0; i < lenOppsite; i++){			
			operand[sub+i] = operand[sub+i] - oppsite[i] + '0';
		}	
		straightenOutNumber(operand, sub+lenOppsite);
		return 1;
	}else{
		return 0;
	}		
}

int main(void){
	char haveMoney[10001];
	char amountPerson[10001];
	int lenHaveMoney = 0, lenAmountPerson = 0, subLength, countDivisor = 0, isZero = 1;
	
	scanf("%s %s", haveMoney, amountPerson);	

	while(haveMoney[lenHaveMoney++] != 0) {}
	while(amountPerson[lenAmountPerson++] != 0){}
	subLength = lenHaveMoney - lenAmountPerson;					
	
	while(1){
		if(minus(haveMoney, amountPerson, lenAmountPerson - 1, subLength)){
			countDivisor++;			
		}else{
			break;
		}
	}	
	printf("%d\n", countDivisor);
	for(int i = 0, size = lenHaveMoney - 1; i < size; i++){
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
