#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 1000

typedef struct tagPillar{short x; short y; } Pillar;

Pillar Pillars[MAX];

int ComparePillarX(const void *a, const void *b){
    int n1 = ((Pillar*)a)->x;
    int n2 = ((Pillar*)b)->x;
    
    if(n1 > n2) return 1;
    else if(n1 < n2) return -1;
    return 0;
}

void PrintPillars(int N){
    for(int i = 0; i < N; i++)
        printf("[P%d] %d %d\n", i, Pillars[i].x, Pillars[i].y);
}

int GetHighestPillarIdx(int l, int r){
    int m = l;
    for(int i = l + 1; i <= r; i++)
        if(Pillars[m].y < Pillars[i].y) m = i;
    return m;
}

int GetMinWarehouse(int N){
    int r = N - 1, m, h, area = 0, pre;
    //Center
    pre = m = h = GetHighestPillarIdx(0, r);
    area = Pillars[m].y;
    //Left
    while(h > 0){
        h = GetHighestPillarIdx(0, h - 1);
        area = area + Pillars[h].y * (Pillars[pre].x - Pillars[h].x);
        pre = h;
    }
    //Right
    pre = h = m;
    while(h < r){
        h = GetHighestPillarIdx(h + 1, r);
        area = area + Pillars[h].y * (Pillars[h].x - Pillars[pre].x);
        pre = h;
    }
    return area;
}


int main(void){
    int N, L, H;
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d%d", &L, &H);
        Pillars[i].x = L;
        Pillars[i].y = H;
    }
    qsort(Pillars, N, sizeof(Pillar), ComparePillarX);
    printf("%d", GetMinWarehouse(N));
    return 0;
}
