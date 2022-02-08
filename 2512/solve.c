#include <stdio.h>

int Request[10000];

int GetAnwser(int N, int M, int T)
{
    int start = 0, end = M, m, sum;
 
    while (start <= end) {
        m = (start + end) / 2;
        sum = 0;
        for (int i = 0; i < N; i++) sum += Request[i] > m ? m : Request[i];
        if (sum > T) end = m - 1;
        else start = m + 1;
    }
    return end;
}
 
int main(void)
{
    int M = 0, N, T;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &Request[i]);
        if (Request[i] > M) M = Request[i];
    }
    scanf("%d", &T);
    printf("%d", GetAnwser(N, M, T));
    return 0;
}
