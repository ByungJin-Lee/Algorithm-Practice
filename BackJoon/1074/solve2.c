/*
	P_Name : "Z"
	Perhaps There is Two Way
*/
#include <stdio.h>

typedef struct Destination{
	int col;
	int row;
} Destination;

int main(void){
	int N = 0, sizeN = 1, visitiedSum = 0, start, last, mid, offset, skip;
	Destination dest;
	
	scanf("%d%d%d", &N, &dest.col, &dest.row);
	
	for(int i = N; i > 0; sizeN*=2, i--);
	start = 0; last = sizeN; offset = start + (last-start)/2;	
	while(N--){					
		mid = start + (last-start)/2;
		skip = (mid-start)*(mid-start);
		if(dest.col < offset && dest.row < mid){			
			last = mid;
			offset -= (last - start)/2;			
		}else if(dest.col < offset && dest.row >= mid){									
			start = mid;
			offset -= (last - start)/2;
			visitiedSum += skip;
		}else if(dest.col >= offset && dest.row < mid){								
			last = mid;
			offset += (last - start)/2;
			visitiedSum += skip*2;
		}else if(dest.col >= offset && dest.row >= mid){		
			start = mid;			
			offset += (last - start)/2;
			visitiedSum += skip*3;
		}
	}
	printf("%d", visitiedSum);
	return 0;
}
