#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N_SIZE 100
#define K_SIZE 100000
#define DP_N_SIZE (N_SIZE + 1)
#define DP_K_SIZE (K_SIZE + 1)

int main(void){
    //Malloc
    int* dp[DP_N_SIZE];
    for(int i = 0; i < DP_N_SIZE; i++)
        dp[i] = (int*)malloc(sizeof(int) * DP_K_SIZE);
    int thing_w[N_SIZE], thing_v[N_SIZE];
    int N, K, P, V, W;
    
    scanf("%d%d", &N, &K);
    for(int i = 0; i < N; i++)
        scanf("%d%d", &thing_w[i], &thing_v[i]);
    
    memset(dp[0], 0, sizeof(int) * (K + 1));
    
    for(int n = 1; n <= N; n++){
        V = thing_v[n - 1];
        W = thing_w[n - 1];
        for(int k = 0; k <= K; k++){
            P = dp[n - 1][k];
            if(W > k){
                dp[n][k] = P;
            }else{
                if(V + dp[n-1][k - W] > P){
                    dp[n][k] = V + dp[n-1][k-W];
                }else{
                    dp[n][k] = P;
                }
            }
        }
    }
    printf("%d", dp[N][K]);
    
    return 0;
}
