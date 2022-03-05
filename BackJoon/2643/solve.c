#include <stdio.h>
#include <stdlib.h>
#define SWAP(t, a, b) t = a; a = b; b = t

typedef struct tagRect{ int x, y; } Rect;

Rect Rects[100];
int RectInners[100];

int Compare(const void *a, const void *b){
    Rect n1 = *(Rect*)a, n2 = *(Rect*)b;
    
    if(n1.x > n2.x) return 1;
    
    if(n1.x == n2.x && n1.y > n2.y) return 1;
    
    if(n1.x == n2.x && n1.y == n2.y) return 0;
    
    return -1;
}

int main(void)
{
    int N, T;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d%d", &Rects[i].x, &Rects[i].y);
        if(Rects[i].x > Rects[i].y){
            SWAP(T, Rects[i].x, Rects[i].y);
        }
    }
    qsort(Rects, N, sizeof(Rect), Compare);
    for(int i = 0; i < N; i++){
        RectInners[i] = 1;
        for(int j = 0; j < i; j++){
            if(Rects[i].y >= Rects[j].y)
                RectInners[i] = RectInners[j] >= RectInners[i] ? RectInners[j] + 1 : RectInners[i];
        }
    }
    for(int i = 1; i < N; i++) RectInners[0] = RectInners[i] > RectInners[0] ? RectInners[i] : RectInners[0];
    printf("%d", RectInners[0]);
    return 0;
}
