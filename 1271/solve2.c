/*
	P_Name : "Much Money"
*/
#include <stdio.h>

int main(void){
	char haveMoney[10001];
	char amountPerson[10001];
	int lenHaveMoney = 0, lenAmountPerson = 0, sub, minus, countDivisor = 0, i, carry;
	
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
		for(i = 0; haveMoney[i] >= '0' && i <= sub; i++);			
		if(i <= sub ){
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
	for(i = 0; haveMoney[i]=='0' && i < lenHaveMoney;i++);
	if(i==lenHaveMoney)
		printf("0");
	else
		printf("%s", haveMoney+i);
	return 0;
}
