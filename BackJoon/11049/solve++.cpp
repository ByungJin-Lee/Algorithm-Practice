#include <iostream>
#include <cstring>

using namespace std;

inline int Multi(int* arr, int s, int k, int l){
    return arr[s] * arr[k+1] * arr[l+1];
}

int CountMulti(int* d_arr, int len){
    int dp[500][500];
    memset(dp, 0, sizeof(dp));
    for(int l = 1; l < len; l++){
        for(int j = l; j < len; j++){
            int mn = -1;
            for(int k = j - l; k < j; k++){
                int v = dp[j-l][k] + dp[k + 1][j] + Multi(d_arr, j-l, k,j);
                if(mn == -1 || mn > v) mn = v;
            }
            dp[j-l][j] = mn;
        }
    }
    
    return dp[0][len-1];
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int d_len, d_arr[501];
    
    cin >> d_len >> d_arr[0] >> d_arr[1];
    
    for(int i = 1, ign; i < d_len; i++)
        cin >> ign >> d_arr[i+1];
    
    cout << CountMulti(d_arr, d_len);
    
    return 0;
}
