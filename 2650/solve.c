#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define L_SIZE 4
#define L_LEN 50

unsigned char visited[26], inter[26][26];

typedef struct tagPoint{ int kind, pos; } Point;
typedef struct tagLayor{ int size; Point points[25]; } Layor;
Layor Layors[L_SIZE];

int Compare(const void *a, const void *b){
    int n1 = ((Point*)a)->pos;
    int n2 = ((Point*)b)->pos;
    
    if(n1 > n2) return 1;
    if(n1 < n2) return -1;
    return 0;
}
int RCompare(const void *a, const void *b){
    int n1 = ((Point*)a)->pos;
    int n2 = ((Point*)b)->pos;
    
    if(n1 > n2) return -1;
    if(n1 < n2) return 1;
    return 0;
}

int GetCountBetweenDots(int l, int pi){
    int count = 0, i = l, j = pi + 1, K = Layors[l].points[pi].kind, T;
    memset(visited, 0, sizeof(unsigned char) * 26);
    while(1){
        for(int r = Layors[i].size; j < r; j++){
            T = Layors[i].points[j].kind;
            
            if(T == K) return count;
            
            if(visited[T]){
                inter[K][T] = 0;
                count--;
            }else{
                inter[K][T] = visited[T] = 1;
                count++;
            }
        }
        j = 0;
        i = (i+1) % 4;
    }
}

int main(void){
    for(int i = 1; i < 26; i++) memset(inter, 0, sizeof(unsigned char) * 26);
    Layors[0].size = Layors[1].size = Layors[2].size = Layors[3].size = 0;
    int N, ACC = 0, Min = 0;
    scanf("%d", &N);
    N /= 2;
    Point p1, p2;
    for(int i = 1, l1, l2, d1, d2; i <= N; i++){
        scanf("%d%d%d%d", &l1, &d1, &l2, &d2);
        p1.kind = p2.kind = i; p1.pos = d1; p2.pos = d2;
        if(l1 == 3) l1 = 2;
        else if(l1 == 2) l1 = 3;
        if(l2 == 3) l2 = 2;
        else if(l2 == 2) l2 = 3;
        l1--; l2--;
        Layors[l1].points[Layors[l1].size++] = p1;
        Layors[l2].points[Layors[l2].size++] = p2;
    }
    for(int i = 0; i < 4; i++) qsort(Layors[i].points, Layors[i].size, sizeof(Point), (i == 0 || i == 3) ? RCompare : Compare);
    
    for(int l = 0, T; l < 4; l++){
        for(int k = 0, r = Layors[l].size; k < r; k++){
            T = GetCountBetweenDots(l, k);
            if(Min < T) Min = T;
        }
    }
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(inter[i][j]){
                ACC++;
                inter[j][i] = 0;
            }
        }
    }
    printf("%d\n%d", ACC, Min);
    return 0;
}
