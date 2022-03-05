#include <stdio.h>

unsigned char Paper[101][101];

int GetMaxArea(int R, int C){
    int Max = 0, Temp;
    for(int r = 0, prev_r = 0, prev_c; r <= R; r++){
        if(Paper[r][0] != 1 && r != R) continue;
        prev_c = 0;
        for(int c = 0; c <= C; c++){
            if(Paper[r][c] != 2 && c != C) continue;
            Temp = (c - prev_c) * (r - prev_r);
            if(Max < Temp) Max = Temp;
            prev_c = c;
        }
        prev_r = r;
    }
    return Max;
}

int main(void)
{
    int R, C, N, TY, Tar;
    scanf("%d%d%d", &C, &R, &N);
    for(int i = 0; i < N; i++){
        scanf("%d%d", &TY, &Tar);
        if(TY) for(int k = 0; k <= R; k++) Paper[k][Tar] = 2;
        else for(int k = 0; k <= C; k++) if(Paper[Tar][k] != 2) Paper[Tar][k] = 1;
    }
    printf("%d", GetMaxArea(R,C));
    
    return 0;
}
