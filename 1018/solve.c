/*
	P_Name : "Repaint Chess Board"
*/
#include <stdio.h>
#include <stdlib.h>

int main(void){
	//Variables
	int inWidth, inHeight, O_h;
	int **vTable; char **chessTable;
	//Work
	scanf("%d%d", &inHeight, &inWidth);
	//Dynamics - chess Table
	chessTable = (char**)malloc(sizeof(char*)*inHeight);
	for (int i = 0; i < inHeight; chessTable[i++] = (char*)malloc(sizeof(char)*inWidth+1));
	O_h = inHeight;
	//Clear Buffer
	while (getchar() != '\n');
	//Input 
	for (int i = 0; i < O_h; scanf("%s", chessTable[i++]));	
	//Check Table
		//for (int i = 0; i < O_h; printf("%s\n", chessTable[i++]));	
	//Dynamics - checking table
	inWidth -= 7; inHeight -= 7;
	vTable = (int**)malloc(sizeof(int*)*inHeight);
	for (int i = 0; i < inHeight; vTable[i++] = (int*)malloc(sizeof(int)*inWidth));
	//Search
	for (int h = 0; h < inHeight; h++){
		char nextLetter = 'W';
		for (int w = 0; w < inWidth; w++, nextLetter = 'W'){
			int checkCount, result = 0;
			//Check Board
			do{
				//init
				checkCount = 0;
				//Work - Check
				for (int inH = h, hSize = h + 8; inH < hSize; inH++){
					//Check width
					for (int inW = w, wSize = w + 8; inW < wSize; inW++){
						if (chessTable[inH][inW] != nextLetter) checkCount++;
						if (inW == wSize - 1) break;
						if (nextLetter == 'W') nextLetter = 'B';
						else nextLetter = 'W';										
					}
				}				
				//Save reselt
				result = 100 * result + checkCount;
				//Exit - Change
				if (nextLetter == 'W') nextLetter = 'B';
				else nextLetter = 0;
			} while (nextLetter == 'B');
			//Save result
			vTable[h][w] = result;
		}
	}
	//Display	
	int min = 64;
	for (int h = 0; h < inHeight; h++){		
		for (int w = 0, tempLeft, tempRight; w < inWidth; w++){
			tempLeft = vTable[h][w] / 100;
			tempRight = vTable[h][w] % 100;
			if (tempLeft < min) min = tempLeft;
			if (tempRight < min) min = tempRight;
		}					
	}
	//Result
	printf("%d\n", min);
	//Free	
	for (int i = 0; i < O_h; free(chessTable[i++]));
	free(chessTable);
	for (int i = 0; i < inHeight; free(vTable[i++]));
	free(vTable);
}
