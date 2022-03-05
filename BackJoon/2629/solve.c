#include <stdio.h>
#include <string.h>
#include <math.h>

#define W_SIZE 30
#define W_V_MAX 500
#define B_SIZE 7
#define DP_COL_MAX W_V_MAX * W_SIZE
#define DP_ROW_MAX W_SIZE

int w_values[W_SIZE];
int b_values[B_SIZE];
int dp[DP_ROW_MAX + 1][DP_COL_MAX + 1]; //Include None

void CompleteDP(int N, int T){
    //None Value Setting
    memset(dp[0], 0, sizeof(int) * (DP_COL_MAX + 1));
    
    int Wv, floor;//Extra Weight
    for(int row = 1; row <= N; row++){
        Wv = w_values[row - 1];
        for(int col = 0; col <= T; col++){ //Col is Total Weight
            floor = dp[row - 1][col];
            if(Wv > col){
                dp[row][col] = floor;
            }else{
                if(Wv + dp[row - 1][col - Wv] > floor){
                    dp[row][col] = Wv + dp[row - 1][col - Wv];
                }else{
                    dp[row][col] = floor;
                }
            }
        }
    }
}

int IsMake(int V, int N, int T){
    if(V > T) return 0;
    
    if(V == T) return 1;
    
    for(int d = 0, r = T - V; d < r; d++){
        if(dp[N][d + V] == d + V && dp[N][d] == d){
            return 1;
        }
    }
    return 0;
}

int main(void){
    int w_n, b_n, total = 0;
    //Input
    scanf("%d", &w_n);
    for(int i = 0; i < w_n; i++){
        scanf("%d", &w_values[i]);
        total += w_values[i];
    }
        
    scanf("%d", &b_n);
    for(int i = 0; i < b_n; i++)
        scanf("%d", &b_values[i]);
    
    CompleteDP(w_n, total);
    //Output
    for(int i = 0; i < b_n; i++){
        if(IsMake(b_values[i], w_n, total)){
            printf("Y");
        }else{
            printf("N");
        }
        printf(" ");
    }
    
    
    return 0;
}
