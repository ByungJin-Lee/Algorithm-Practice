/*
	P_Name : "Maze Searching"
*/
#include <stdio.h>
#include <stdbool.h>

bool MAZE[101][101];
bool FLAGS[101][101];
int willX[10000], willY[10000];
char buffer[101];

int bfs(int N, int M){	
	//Setting
	int dy[4] = {0, 1, 0, -1};
	int dx[4] = {1, 0, -1, 0};
	int len = 1;
	int s = 0, l = 1, d = 1;
	willX[s] = 0; willY[s] = 0;
	while(s != l){
		for(int i = s, xN, yM; i < l; i++){				
			for(int j = 0; j < 4; j++){
				//Position Setting
				xN = willX[i] + dx[j];
				yM = willY[i] + dy[j];				
				//Check Position
				if(xN < 0 || yM < 0 || xN >= N || yM >= M) continue;
				//Check MAZE
				if(!MAZE[xN][yM] || FLAGS[xN][yM]) continue;
				//Arrive then return
				if(xN == N - 1 && yM == M - 1) return len + 1;
				//Check Visit
				FLAGS[xN][yM] = true;
				//report MAZE road
				willX[d] = xN; willY[d] = yM;
				//Increase Index
				d++;
			}
		}		
		//Increase Length and ready next;
		len++;
		s = l;
		l = d;
	}
	return len;
}

int main(void){
	//Variables
	int N, M;
	//Input
	scanf("%d%d", &N, &M);
	for(int i = 0; i < N; i++){
		scanf("%s", buffer);
		for(int j = 0; j < M; j++)
			MAZE[i][j] = (buffer[j] == '1') ? true : false;
	}		
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			FLAGS[i][j] = false;
		}
	}	
	//Work - Display		
	printf("%d", bfs(N, M));
	return 0;
}
