#include <stdio.h>
#define Circle(V, D, C) (V + D) % C

int GetKYear(void){
    int FS, BS, F, B, FD, BD, Y, Delta;
    F = B = 0; Y = 1;
    scanf("%d%d%d%d", &FS, &BS, &FD, &BD);
    Delta = FD - 1; BD--;
    for(int i = 0; i < BS; i++){
        if(Circle(B, Delta, BS) == BD) return Y + Delta;
        B = Circle(B, FS, BS);
        Y += FS;
    }
    return -1;
}

int main(void)
{
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) printf("%d\n", GetKYear());
    return 0;
}
