/*
	P_Name : "Z"
	Perhaps There is Two Way
*/
#include <stdio.h>

unsigned int orderColRow = 0;
unsigned int resultOrder = 0;

typedef struct Destination{
	int column;
	int row;
} Destination;


void countingOrderZ(int start, int last, int offset, Destination *dest){	
	if(resultOrder != 0) return;
	if(last - start == 2){
		for(int col = offset, height = offset + 2; col < height; col++){
			for(int row = start, width = row + 2; row < width; row++){
				if(col == dest->column && row == dest->row){					
					resultOrder = orderColRow;
				}else{
					orderColRow++;					
				}
			}
		}
		return;
	}else{
		int mid = start + (last -start)/2;
		countingOrderZ(start, mid, offset, dest);
		countingOrderZ(mid, last, offset, dest);
		countingOrderZ(start, mid, mid - start + offset, dest);
		countingOrderZ(mid, last, mid - start + offset, dest);
	}
}

int main(void){
	int N = 0, sizeN = 1;
	Destination dest;
	scanf("%d%d%d", &N, &dest.column, &dest.row);	
	while(N-- > 0) sizeN *= 2;
	countingOrderZ(0, sizeN, 0, &dest);
	printf("%d", resultOrder);
	return 0;
}
