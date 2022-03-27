#include <iostream>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, K, M = 0;
    
    cin >> N >> K;
    
    char chairs[20001];
    
    cin >> chairs;
    
    for(int i = 0; i < N; i++){
        if(chairs[i] != 'P') continue;
        
        for(int l = max(0, i - K), r = min(N, i + K + 1); l < r; l++){
            if(chairs[l] == 'H'){
                M++;
                chairs[l] = 0;
                break;
            }
        }
    }
    cout << M;
    
    return 0;
}
