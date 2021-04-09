/*
	P_Name : "Maze Searching"
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool MAZE[100][100] = {false};
bool FLAGS[100][100] = {false};

int bfs_recur(int vX, int vY, int N, int M, int c_steps){	
	//Cut
	if(FLAGS[vY][vX] || !MAZE[vY][vX] || vX < 0 || vX > M || vY < 0 || vY > N) return -1;
	//End Condition
	if(vY == N && vX == M) return c_steps;	
	//Flag Vertex	
	FLAGS[vY][vX] = true;		
	int resultArray[4];
	//1st - right
	resultArray[0] = bfs_recur(vX+1, vY, N, M, c_steps + 1);
	//2nd - down
	resultArray[1] = bfs_recur(vX, vY+1, N, M, c_steps + 1);
	//3th - left
	resultArray[2] = bfs_recur(vX-1, vY, N, M, c_steps + 1);	
	//4th - up
	resultArray[3] = bfs_recur(vX, vY-1, N, M, c_steps + 1);	
	//count = min value
	int count = -1;
	for(int i = 0; i < 4; i++){		
		if(resultArray[i] == -1) continue;
		//compare
		if(count == -1) count = resultArray[i];
		if(count > resultArray[i]) count = resultArray[i];
	}	
	return count;
}

int main(void){
	//Variables
	int N, M, min;
	//Input
	scanf("%d%d", &N, &M);
	//-create Maze
	int input;
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; MAZE[i][j++] = input) scanf("%1d", &input);
	//Work	
	//Display
	printf("%d", bfs_recur(0,0, N-1, M-1, 1));
	return 0;
}
