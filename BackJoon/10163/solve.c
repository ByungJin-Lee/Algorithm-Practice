#include <stdio.h>

unsigned char A[1001][1001];
int AC[101];

int main(void){
    int N, I, sx, sy, dx, dy, ex, h, rucursion;
    scanf("%d", &N);
    I = N;
    while(I != 0){
        scanf("%d%d%d%d", &sx, &sy, &ex, &h);
        AC[I] = rucursion = ex * h;
        ex += dx = sx;
        dy = sy;
        while(rucursion != 0){
            if(dx == ex){
                dy++;
                dx = sx;
            }
            AC[A[dy][dx]]--;
            A[dy][dx] = I;
            dx++;
            rucursion--;
        }
        I--;
    }
    for(I = N; I != 0; I--) printf("%d\n", AC[I]);
    return 0;
}
