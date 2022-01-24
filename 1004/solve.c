#include <stdio.h>

#define GetDistance(dx, dy) ((dx) * (dx) + (dy) * (dy))
#define IsContained(x, y, cx, cy, r) (GetDistance(cx - x, cy - y) < r * r)

int main(void){
    int T, N, C, sx, sy, dx, dy, cx, cy, r;
    scanf("%d", &T);
    for(int i = 0; i < T; i++){
        scanf("%d%d%d%d", &sx, &sy, &dx, &dy);
        scanf("%d", &N);
        C = 0;
        for(int j = 0; j < N; j++){
            scanf("%d%d%d", &cx, &cy, &r);
            if(IsContained(sx, sy, cx, cy, r) != IsContained(dx, dy, cx, cy, r)) C++;
        }
        printf("%d\n", C);
    }
    return 0;
}
