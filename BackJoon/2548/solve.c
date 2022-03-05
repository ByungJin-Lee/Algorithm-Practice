#include <stdio.h>
#include <stdlib.h>

short Datas[20000];

int Compare(const void *a, const void *b){
    short n1 = *(short*)a, n2 = *(short*)b;
    if(n1 > n2) return 1;
    if(n2 > n1) return -1;
    return 0;
}

int main(void)
{
    int N, S = 0, P = 0, M = 100010000;
    scanf("%d", &N);
    for(int i = 0; i < N; P += Datas[i], i++) scanf("%d", &Datas[i]);
    qsort(Datas, N, sizeof(short), Compare);
    P = P - (Datas[0] - 1) * N;
    for(int j = Datas[0], e = Datas[N-1], left = 0; j <= e; j++){
        P = P + left - N + left;
        if(M > P) { M = P; S = j; }
        else break;
        for( ; j == Datas[left] && left < N; left++);
    }
    printf("%d", S);
    return 0;
}
