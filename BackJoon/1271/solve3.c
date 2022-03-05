/*
	P_Name : "Much Money"
*/
#include <stdio.h>

int main(void){
	char haveMoney[10001];
	char amountPerson[10001];
	int lenHaveMoney = 0, lenAmountPerson = 0, countDivisor = 0, sub, i, carry, result;
	
	scanf("%s %s", haveMoney, amountPerson);	

	while(haveMoney[lenHaveMoney++] != 0) {}
	while(amountPerson[lenAmountPerson++] != 0){}
	lenHaveMoney--; lenAmountPerson--;
	sub = lenHaveMoney - lenAmountPerson;					
	
	while(1){			
		carry = 0; result = 0;
		
		for(i = lenAmountPerson - 1; i >= 0; i--){
			result = haveMoney[sub + i] - amountPerson[i] + carry;
			if(result < 0){
				carry = -1;
				result = result + 10;
			}else{
				carry = 0;
			}
			haveMoney[sub + i] = result + 48;						
		}		
		countDivisor++;
		//Check End
		if (carry < 0){
			if(sub){
				haveMoney[sub-1] = haveMoney[sub-1] - 1;	
				for(i = sub - 1; i > 0; i--){
					if(haveMoney[i] < '0'){
						haveMoney[i] += 10;
						haveMoney[i-1] -= 1;
					}
				}
				if(haveMoney[0] < '0') break;
			}else{
				break;
			}
		}
	}
	carry = 0; result = 0;
	for(i = lenAmountPerson - 1; i >= 0; i--){
		result = haveMoney[sub + i] + amountPerson[i] + carry - 96;
		carry = result / 10;
		haveMoney[sub + i] = result%10 + 48;
	}
	for(i = sub - 1; i >= 0; i--){
		result = haveMoney[i] + carry - 48;
		carry = result / 10;
		haveMoney[i] = result%10 + 48;
	}
	printf("%d\n", countDivisor-1);
	for(i = 0; haveMoney[i]=='0' && i < lenHaveMoney;i++);
	if(i==lenHaveMoney)
		printf("0");
	else
		printf("%s", haveMoney+i);
	return 0;
}
