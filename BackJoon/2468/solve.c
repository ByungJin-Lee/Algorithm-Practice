/*
	P_Name : "Safe Area"
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void recursive(bool **_zeroMap, int size, int x, int y);
int searchDFS(bool **_zeroMap, int size);
void updateMap(bool **_zeroMap, int **_map, int size, int deep);

int main(void){
	//Variables
	int size, min, max, result = 1;
	int **map;
	bool  **zero_map;
	//Input
	scanf("%d", &size);
	//-create Dynamics 2 Array and allocate
	map = (int**)malloc(sizeof(int*)*size);
	zero_map = (bool**)malloc(sizeof(bool*)*size);
	for(int i = 0; i < size; map[i++] = (int*)malloc(sizeof(int)*size));
	for(int i = 0; i < size; zero_map[i++] = (bool*)malloc(sizeof(bool)*size));
	//--inputValue
	min = 100; max = 1;	
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			scanf("%d", &map[i][j]);
			//---get MinValue and MaxValue
			if(map[i][j] > max) max = map[i][j];
			if(map[i][j] < min) min = map[i][j];
		}
	}
	//Work
	for(int i = min, temp; i <= max; i++){
		updateMap(zero_map,map,size,i);			
		if((temp = searchDFS(zero_map,size)) > result) result = temp;
	}
	//Display
	printf("%d", result);
	return 0;
}
void recursive(bool **_zeroMap, int size, int x, int y){		
	//Check this
	_zeroMap[y][x] = false;
	//-direction search up and down
	int pos = 0;
	for(int ud = 1, ud_count = 0; ud_count < 2; ud_count++,ud = -1){
		pos = y + ud; 
		//--check range
		if(pos < 0 || pos >= size) continue;
		//alright
		if(_zeroMap[pos][x]){			
			recursive(_zeroMap, size, x, pos);
			_zeroMap[pos][x] = false;
		}
	}
	//--direction search left and right
	for(int lr = 1, lr_count = 0; lr_count < 2; lr_count++, lr= -1){
		pos = x + lr; 
		//--check range
		if(pos < 0 || pos >= size) continue;
		//--alright
		if(_zeroMap[y][pos]){			
			recursive(_zeroMap, size, pos, y);
			_zeroMap[y][pos] = false;
		}
	}	
	return;
}
int searchDFS(bool **_zeroMap, int size){
	int count = 0;
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			//Check - If is not then next
			if(!_zeroMap[i][j])continue;
			//Check - right - clock search
			count++;			
			recursive(_zeroMap, size, j, i);			
		}
	}
	return count;
}
void updateMap(bool **_zeroMap, int **_map, int size, int deep){
	//if value is more than deep, save 1.
	for(int i = 0; i < size; i++)
		for(int j = 0; j < size; _zeroMap[i][j] = (_map[i][j]>deep)? true:false, j++);
}
