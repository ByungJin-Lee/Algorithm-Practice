#include <stdio.h>
#include <string.h>

#define N_SIZE 50
typedef unsigned char BYTE;

BYTE adj[N_SIZE][N_SIZE];
int depth_per_member[N_SIZE];
int min = 999, min_count = 0;

void bfs(int N){
    int start, last, shift, depth;
    int Que[N_SIZE], V;
    BYTE nvisited[N_SIZE];
    
    for(int i = 0; i < N; i++){
        start = shift = depth = 0;
        last = 1;
        Que[0] = i;
        //Visited
        memset(nvisited, 1, sizeof(BYTE) * N_SIZE);
        nvisited[i] = 0;
        //Calc Depth
        while(last - start > 0){
            for(int qi = start; qi < last; qi++){
                V = Que[qi];
                //Check In Adj using Que Value
                for(int k = 0; k < N; k++){
                    if(adj[V][k] && nvisited[k]){
                        nvisited[k] = 0;
                        Que[last + shift] = k;
                        shift++;
                    }
                }
            }
            start = last;
            last += shift;
            shift = 0;
            depth++;
        }
        
        depth_per_member[i] = depth - 1;
        if(min > depth_per_member[i]){
            min = depth_per_member[i];
            min_count = 1;
        }else if(min == depth_per_member[i]){
            min_count++;
        }
    }
}

int main(void){
    int N, m_1, m_2;
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        memset(adj[i], 0, sizeof(BYTE) * N);
    while(1){
        scanf("%d%d", &m_1, &m_2);
        if(m_1 == -1 && m_2 == -1) break;
        m_1--; m_2--;
        adj[m_1][m_2] = adj[m_2][m_1] = 1;
    }
    
    bfs(N);
    
    printf("%d %d\n", min, min_count);
    for(int i = 0; i < N; i++)
        if(depth_per_member[i] == min) printf("%d ", i + 1);
    return 0;
}
