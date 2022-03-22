#include <iostream>
#include <cstring>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    bool prime[10001];
    memset(prime, true, sizeof(prime));
    
    for(int i = 2; i < 100; i++){
        if(prime[i])
            for(int j = 2 * i; j <= 10000; j+=i) prime[j] = false;
    }
    
    int N, V;
    
    cin >> N;
    
    for(int i = 0; i < N; i++){
        cin >> V;
        for(int l = V >> 1, r = l; l > 1; l--, r++){
            if(prime[l] && prime[r]){
                cout << l << ' ' << r << '\n';
                break;
            }
        }
    }
    
    
    return 0;
}
