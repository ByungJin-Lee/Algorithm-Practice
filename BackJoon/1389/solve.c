#include <stdio.h>
#include <string.h>

char F_Inter[101][101];

int GetKevinValue(int T, int V){
    int k_v = 0, e = 1, l, r, d, que[100];
    char visited[101];
    memset(visited, 0, sizeof(char)*101);
    l = d = 0; r = 1;
    que[0] = T; visited[T] = 1;
    
    while(r-l){
        for(int i = l; i < r; i++){
            for(int j = 1; j <= V; j++){
                if(!visited[j] && F_Inter[que[i]][j]){
                    visited[j] = 1;
                    que[r + d] = j;
                    d++;
                    k_v += e;
                }
            }
        }
        
        l = r;
        r += d;
        d = 0;
        e++;
    }
    
    return k_v;
}

int main(void)
{
    int V, E, M, MI = 1;
    scanf("%d%d", &V, &E);
    for(int i = 0, s, e; i < E; i++){
        scanf("%d%d", &s,&e);
        F_Inter[s][e] = F_Inter[e][s] = 1;
    }
    M = GetKevinValue(1, V);
    for(int i = 2, t; i <= V; i++){
        t = GetKevinValue(i, V);
        if(M > t) { M = t; MI = i; }
    }
    printf("%d", MI);
    return 0;
}
