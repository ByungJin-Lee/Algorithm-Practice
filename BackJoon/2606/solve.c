#include <stdio.h>
#include <string.h>

char Computer_Inter[100][100];

int SpreadVirus(int V){
    int count_victim = 0, l, r, d, que[100];
    char visited[100];
    memset(visited, 0, sizeof(char) * 100);
    que[0] = 0; visited[0] = 1;
    l = d = 0;
    r = 1;
    while(r - l > 0){
        for(int i = l; i < r; i++){
            for(int j = 0; j < V; j++){
                if(Computer_Inter[que[i]][j] && !visited[j]){
                    count_victim++;
                    visited[j] = 1;
                    que[r + d] = j;
                    d++;
                }
            }
        }
        l = r;
        r += d;
        d = 0;
    }
    
    
    l = d = 0;
    r = 1;
    
    return count_victim;
}

int main(void)
{
    int V, E;
    scanf("%d%d", &V, &E);
    for(int i = 0, s, e; i < E; i++){
        scanf("%d%d", &s,&e); s--; e--;
        Computer_Inter[s][e] = Computer_Inter[e][s] = 1;
    }
    printf("%d", SpreadVirus(V));
    return 0;
}
