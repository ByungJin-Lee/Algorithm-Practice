#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

unsigned int CountCaseOfRequired(vector<unsigned int>& coins, unsigned int required){
    unsigned int len = (unsigned int)coins.size();
    
    unsigned int dp[10001];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for(int i = 0; i < len; i++){
        unsigned int c = coins[i];
        for(unsigned int req = c; req <= required; req++)
            if(req >= c) dp[req] += dp[req-c];
    }
    return dp[required];
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    unsigned int kindOfCoin, value, required;
    vector<unsigned int> coins;
    
    cin >> kindOfCoin >> required;
    
    while(kindOfCoin-- != 0){
        cin >> value;
        coins.push_back(value);
    }
    
    cout << CountCaseOfRequired(coins, required);
    
    return 0;
}
