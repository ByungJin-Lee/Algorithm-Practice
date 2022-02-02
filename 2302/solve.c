#include <stdio.h>
#define MAX 41

int main(void){
    int DP[MAX], N, S, AC = 1, pre = 1;
    DP[0] = DP[1] = 1;
    DP[2] = 2;
    scanf("%d%d", &N, &S);
    for(int i = 3; i <= N; i++) DP[i] = DP[i-1] + DP[i-2];
    for(int i = 0, cur; i < S; i++){
        scanf("%d", &cur);
        AC *= DP[cur - pre];
        pre = cur + 1;
    }
    AC *= DP[N - --pre];
    printf("%d", AC);
    return 0;
}
