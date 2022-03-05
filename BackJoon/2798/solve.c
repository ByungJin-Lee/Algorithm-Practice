/*
	P_Name : "Black Jack"
*/
#include <stdio.h>
#include <stdlib.h>

int main(void){
	//Variables
	int count_cards, standard, result;
	int *card_set, ***value_list;
	//Input
	scanf("%d %d", &count_cards, &standard);
	//-create Dynamics Array
	card_set = (int*)malloc(sizeof(int) * count_cards);
	//--input card Value
	for(int i = 0; i < count_cards; scanf("%d", &card_set[i++]));
	//Work
	//-create 3 value_list Dynamics Array
	value_list = (int***)malloc(sizeof(int**)*count_cards);
	for(int i = 0, size = count_cards-1; i < count_cards; i++){
		value_list[i] = (int**)malloc(sizeof(int*)*size);
		for(int j = 0, size_sub = size-1; j < size; j++)
			value_list[i][j] = (int*)malloc(sizeof(int)*size_sub);			
	}
	//Save value list
	for(int i = 0; i < count_cards; i++){
		for(int j = 0, sub_j = 0; j < count_cards; j++){
			if(i == j) {sub_j++; continue;}
			for(int k = 0, sub_k = 0; k < count_cards; k++){
				if(i == k || j == k){sub_k++; continue;}
				value_list[i][j-sub_j][k-sub_k] = card_set[i] + card_set[j] + card_set[k] - standard;
			}
		}
	}
	//Check Value
//	printf("\nTable\n");
//	for(int i = 0; i < count_cards; i++){
//		printf("i(%d)============\n",i);
//		for(int j = 0, size = count_cards - 1; j < size; j++){
//			printf(" -> j(%d)=============\n", j);
//			for(int k = 0, size_sub = size-1; k < size_sub; k++){
//				printf("[%d] ", value_list[i][j][k]);
//			}
//			printf("\n\n");
//		}
//		printf("\n\n");
//	}
	//Judge
	result = -1*standard;	
	for(int i = 0; result !=0 && i < count_cards; i++){
		for(int j = 0, size = count_cards - 1; result != 0 && j < size; j++){
			for(int k = 0, size_sub = size-1; result != 0 && k < size_sub; k++){
				//If higher than 0, throw away.
				if(value_list[i][j][k] > 0) continue;
				//If equal, then stop work.
				else if(value_list[i][j][k] == 0) result = 0;
				//If less than 0, save near Value
				else{
					if(result < value_list[i][j][k]) result = value_list[i][j][k];
				}
			}
		}
	}
	//Display
	printf("%d", result+standard);
	//Free
	for(int i = 0; i < count_cards; i++){
		for(int j = 0, size = count_cards-1; j < size; j++){
			free(value_list[i][j]);
		}
		free(value_list[i]);
	}
	free(value_list);
	return 0;
}
