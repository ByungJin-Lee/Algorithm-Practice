#include <iostream>
#include <cstring>

using namespace std;

unsigned int Left[2000], Right[2000], dp[2000][2000];

unsigned int Forward(int l, int r, int N){
    if(l == N || r == N) return 0;
    
    if(dp[l][r] != -1) return dp[l][r];
    
    if(Left[l] > Right[r])
        return dp[l][r] = Right[r] + Forward(l, r + 1, N);
    
    return dp[l][r] = max(Forward(l+1, r+1, N), Forward(l+1, r, N));
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(dp, -1, sizeof(dp));
    
    int N, I;
    
    cin >> N;
    I = 0;
    while(I < N) cin >> Left[I++];
    I = 0;
    while(I < N) cin >> Right[I++];
    
    cout << Forward(0, 0, N);
    
    return 0;
}

