#include <stdio.h>
#define Cr(v, N) (v) % N;

int Y[30], X[30];

int main(void)
{
    int N, From = 0, I = 0;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) scanf("%d", &Y[i]);
    while(I < N){
        while(X[From] != 0){
            From = Cr(From + 1, N);
        }
        X[From] = Y[I];
        From = Cr(From + X[From], N);
        I++;
    }
    printf("%d\n", N);
    for(int i = 0; i < N; i++)
        printf("%d ", X[i]);
    return 0;
}
