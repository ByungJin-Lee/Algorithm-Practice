#include <stdio.h>

int Numbers[100001];

int main(void)
{
    int N, C, MAX = -2147483648;
    Numbers[0] = 0;
    scanf("%d%d", &N, &C);
    for(int i = 1, t; i <= N; i++){
        scanf("%d", &t);
        Numbers[i] = Numbers[i-1] + t;
    }
    for(int i = 0, r = N - C, t; i <= r; i++){
        t = Numbers[i + C] - Numbers[i];
        if(MAX < t) MAX = t;
    }
    printf("%d", MAX);
    return 0;
}
