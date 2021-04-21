/*
	P_Name : "Make Word"
*/
#include <stdio.h>

char dic[200001][10];
int dicAlpha[26];
int alpha[26];
int countWord[26];
char buffer[10];

int main(void){
	//Variables
	int index = 0, s = 0, size = 0, v = 0, min, max;
	for(;index < 26; index++){
		dicAlpha[index] = 0;
		alpha[index] = 0;
		countWord[index] = 0;
	}
	index = 0;
	//Input
	while(1){
		scanf("%s", dic[index]); 
		//End Condition
		if(dic[index][0] == '-') break;
		index++;
	}
	size = index;	
	//-Input 2
	while(1){
		//Input puzzle
		scanf("%s", buffer);
		//End Condition
		if(buffer[0] == '#') break;
		//Counting alpha
		index = 0;
		while((v = buffer[index++]) != 0) alpha[v - 65]++;
		//Check dic Word
		for(index = 0; index < size; index++){				
			//Check all spell
			s = 0;
			while((v = dic[index][s]) != 0){
				v = v - 65;
				dicAlpha[v]++;
				//If need more alpha that i have(=alpha[v]) then cant make this word
				if(dicAlpha[v] > alpha[v]){
					s = -1;
					break;
				}
				s++;
			}
			//If can make word; report this alpha consist of word
			if(s != -1)				
				for(s = 0; s < 26; s++)
					if(dicAlpha[s]) countWord[s]++;						
			//Init
			for(s = 0; s < 26; dicAlpha[s++] = 0);
		}
		//All check
		for(index = 0, min = 200000, max = 0; index <26; index++){			
			//Check Min, Max				
			if(min > countWord[index] && alpha[index]) min = countWord[index];
			if(max < countWord[index] && alpha[index]) max = countWord[index];			
		}		
		//Display min
		for(index = 0; index < 26; index++)
			if(countWord[index] == min && alpha[index]) printf("%c", index + 65);
		printf(" %d ", min);
		//Display max
		for(index = 0; index < 26; index++){
			if(countWord[index] == max && alpha[index]) printf("%c", index + 65);
			//reset
			countWord[index] = 0;
			alpha[index] = 0;
		}
		printf(" %d\n", max);
	}	
	return 0;
}
