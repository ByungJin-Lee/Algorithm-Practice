/*
    P_Name : "DFS & BFS"
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool _matrix[1000][1000];
bool isTrue[1000];
int _steps[1000];
int p = 0;

void dfs_search(int vertex, int size){
    //dfs
    //-Save Vertex
    _steps[p++] = vertex;
    isTrue[vertex] = true;
    //-left    
    for(int i = 0; i < size; i++){
    	//Check Vertex
    	if(!isTrue[i] && _matrix[vertex][i]) dfs_search(i, size);
	}	
}

void bfs_search(int vertex, int size){
	//bfs
	int index = 0;
	_steps[index++] = vertex;
	isTrue[vertex] = true;
    //All Checking
    int s = 0, l = 1, tempLast = 1;    
	while(s != l){
		for(int i = s, V; i < l; i++){
			V = _steps[i];		
			for(int j = 0; j < size; j++){					
				//Checking!		
				if(!isTrue[j] && _matrix[V][j]){					
					_steps[index++] = j;
					isTrue[j] = true;
					tempLast++;
				}
			}
		}	
		s = l;
		l = tempLast;
	}
}

int main(void){
    //Variables
    int count_vertex, count_edge, startV;
    //Input
    scanf("%d%d%d", &count_vertex, &count_edge, &startV);        
    //--init array
    for(int i = 0; i < count_vertex; i++)
        for(int j = 0; j < count_vertex; j++)
            _matrix[i][j] = false;
    for(int i = 0; i < count_vertex; _steps[i] = -1, isTrue[i] = false, i++);    
    //--input Edges
    for(int i = 0, x, y; i < count_edge; _matrix[y-1][x-1] = true, _matrix[x-1][y-1] = true, i++) scanf("%d%d", &x,&y);
    //Work
    //-dfs
	dfs_search(startV - 1, count_vertex);
	for(int i  = 0; _steps[i] != -1 && i < count_vertex; printf("%d ", _steps[i++] + 1));
	printf("\n");
	//init
	for(int i = 0; i < count_vertex; _steps[i] = -1, isTrue[i] = false, i++);
	//-bfs
	bfs_search(startV - 1, count_vertex);
	for(int i  = 0; _steps[i] != -1 && i < count_vertex; printf("%d ", _steps[i++] + 1));        
    //Free
    return 0;
}
