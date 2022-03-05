#include <stdio.h>
#include <string.h>

unsigned char Inter[1000][1000];

int GetConnectedComponent(int V){
    int count = 0, l, r, d, que[1000];
    char visited[1000];
    memset(visited, 0, sizeof(char) * 1000);
    
    for(int i = 0; i < V; i++){
        if(visited[i]) continue;
        
        l = d = 0; r = 1;
        que[0] = i;
        visited[i] = 1;
        
        count++;
        
        while(r - l > 0){
            for(int j = l; j < r; j++){
                for(int k = 0; k < V; k++){
                    if(Inter[que[j]][k] && !visited[k]){
                        visited[k] = 1;
                        que[r + d] = k;
                        d++;
                    }
                }
            }
            l = r;
            r += d;
            d = 0;
        }
    }
    
    return count;
}

int main(void)
{
    int V, E;
    scanf("%d%d", &V, &E);
    for(int i = 0; i < V; i++) memset(Inter[i], 0, sizeof(unsigned char) * V);
    for(int i = 0, s, e; i < E; i++){
        scanf("%d%d", &s, &e);
        s--;e--;
        Inter[s][e] = Inter[e][s] = 1;
    }
    printf("%d", GetConnectedComponent(V));
    return 0;
}
