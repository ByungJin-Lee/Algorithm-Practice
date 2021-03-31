/*
	P_Name : "Group Word Checking"
*/
#include <stdio.h>
#include <stdbool.h>

int main(void){
	//Variables
	int w_number, result = 0; //Input Amount of Words and Result
	bool alphaTable[26];
	char buffer[100];
	//Work
	scanf("%d", &w_number);
	for(int i = 0, j = 0; i < w_number; i++, j = 0){
		for(int k = 0; k < 26; alphaTable[k++] = false){}//Clear Table
		while(getchar() != '\n') {} //Clear Input Stream
		scanf("%s", buffer);
		result++;char temp;
		while((temp = buffer[j++]) != 0){			
			if(alphaTable[temp-'a']) {				
				result--;
				break;	
			}else{
				for(int k = j; buffer[k]==temp;k++)
					if(buffer[k+1] != temp) j = k+1;
				alphaTable[temp - 'a'] = true;				
			}
		}
	}
	//Display
	printf("%d", result);
	return 0;
}
