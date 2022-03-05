/*
	P_Name : "Self Number"
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 9999

void notSelf(const int _n, bool _table[]);

int main(void){
	//Variables	
	bool notSelfTable[MAX] = {false};
	//Work
	for(int i = 0; i < MAX; i++)
		notSelf(i+1, notSelfTable);		
	for(int i = 0; i < MAX; i++)
		if(notSelfTable[i] == false) printf("%d\n", i+1);
}
void notSelf(const int _n, bool _table[]){	
	if(_table[_n - 1] == true) return;
	int digit = 1, sum = 0, temp = _n;
	while(_n >= digit) digit*=10;
	while(digit > 1){		
		sum = sum + temp/(digit = digit/10);
		temp = temp % digit;
	}
	if(_n+sum > MAX+1) return; //Stop condition		
	notSelf(_n + sum, _table); //Recursive Function
	_table[_n+sum - 1] = true; //Check Number
}
