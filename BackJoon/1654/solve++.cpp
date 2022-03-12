#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int Lans[10000];

bool GetValue(int K, int N, int M){
    long long v = Lans[K-1] / M;
    
    if(v >= N) return true;
    for(int i = K - 2, t; i >= 0; i--){
        v += t = Lans[i] / M;
        if(v >= N) return true;
        
        if(v + t * i < N) break;
    }
    return false;
}


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    unsigned int K, N, m, r, l = 1, p = 0;
    
    
    cin >> K >> N;
    
    for(int i = K - 1; i >= 0; i--) cin >> Lans[i];
    
    sort(Lans, Lans + K);
    r = Lans[K-1];
    
    while(r - l >= 0){
        m = (l + r) / 2;
        
        if(GetValue(K, N, m))
            l = m + 1;
        else
            r = m - 1;
        
        if(p == m) break;
        
        p = m;
    }
    
    cout << r;
    
    return 0;
}
