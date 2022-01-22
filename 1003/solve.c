#include <stdio.h>
#define DP_SIZE 41
struct BinaryInfo{
    int zero_count;
    int one_count;
};

int main(void){
    int N;
    //DP
    struct BinaryInfo dp[DP_SIZE];
    dp[0].one_count = dp[1].zero_count = 0;
    dp[0].zero_count = dp[1].one_count = 1;
    for(int i = 2; i < DP_SIZE; i++){
        dp[i].one_count = dp[i-1].one_count + dp[i-2].one_count;
        dp[i].zero_count = dp[i-1].zero_count + dp[i-2].zero_count;
    }
    scanf("%d", &N);
    for(int i = 0, input; i < N; i++){
        scanf("%d", &input);
        printf("%d %d\n", dp[input].zero_count, dp[input].one_count);
    }
    return 0;
}
