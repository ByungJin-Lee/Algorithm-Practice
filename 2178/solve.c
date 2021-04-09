/*
	P_Name : "Maze Searching"
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool MAZE[100][100] = {false};
bool FLAGS[100][100] = {false};

int bfs_recur(int vX, int vY, int N, int M, int c_steps){
	//End Condition
	if(vY == N && vX == M) c_steps;
	//Flag Vertex	
	FLAGS[vY][vX] = true;	
	//Check can go
	//-up & down
	int count = 0, pos, max;
	//--result
	int resultArray[4];
	for(int ud = 1; count < 2; count++, ud = -1){		
		pos = vY + ud;
		printf("[%d,%d]\n", vX, pos);
		//Cant go
		if(pos < 0 || pos >= N) {
			resultArray[count] = 0;
			continue;	
		}
		//go
		if(MAZE[pos][vX] && !FLAGS[pos][vX])
			resultArray[count] = bfs_recur(vX, pos, N, M, c_steps + 1);
	}	
	//--left & right	
	printf("->lr\n");
	for(int lr = 1; count < 4; count++, lr = -1){
		pos = vX + lr;
		//Cant go
		if(pos < 0 || pos >= N) {
			resultArray[count] = 0;
			continue;
		}
		//go
		if(MAZE[vY][pos] && !FLAGS[vY][pos])
			resultArray[count] = bfs_recur(pos, vY, N, M, c_steps + 1);
	}
	//count = min value
	count = resultArray[0]; max = count;
	for(int i = 1; i < 4; i++){
		//compare
		if(max < resultArray[i]) max = resultArray[i];
		if(count > resultArray[i]) count = resultArray[i];
	}
	if(max == 0) return c_steps;
	else count;
}

int main(void){
	//Variables
	int N, M, min;
	//Input
	scanf("%d%d", &N, &M);
	//-create Maze
	char input;
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; MAZE[i][j++] = input - '0') scanf("%c", &input);
	//Work
	min = bfs_recur(0,0, N, M, 0);
	//Display
	printf("%d", min);
	return 0;
}
