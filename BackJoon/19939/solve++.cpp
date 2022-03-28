#include <iostream>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, K, S;
    
    cin >> N >> K;
    
    S = K * (K+1) / 2;
    if(S > N) cout << -1;
    else if(S == N) cout << K - 1;
    else cout << ((N - S) % K > 0 ? K : K-1);
    return 0;
}
