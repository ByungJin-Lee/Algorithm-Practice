#include <stdio.h>
#include <stdlib.h>
#define FLO double

FLO Values[100000], ACC_Values[100000];

int Compare(const void *a, const void *b){
    float n1 = *(FLO*)a, n2 = *(FLO*)b;
    if(n1 > n2) return 1;
    if(n2 > n1) return -1;
    return 0;
}

FLO GetAdjustedMean(int N, int K){
    FLO left = K * Values[K], right = K * Values[N-K-1];
    return (ACC_Values[N-K-1] - ACC_Values[K-1] + left + right) / N;
}

int main(void)
{
    int N, K;
    scanf("%d%d", &N, &K);
    for(int i = 0; i < N; i++) scanf("%lf", &Values[i]);
    qsort(Values, N, sizeof(FLO), Compare);
    ACC_Values[0] = Values[0];
    for(int i = 1; i < N; i++) ACC_Values[i] = ACC_Values[i-1] + Values[i];
    printf("%.2lf %.2lf", (ACC_Values[N-K-1] - ACC_Values[K-1]) / (N - 2*K) + 0.00000001, GetAdjustedMean(N, K) + 0.00000001);
    return 0;
}
