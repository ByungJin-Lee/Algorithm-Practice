#include <iostream>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N, M, L, S;
    
    cin >> N >> L;
    M = 2 * N;
    
    for(int i = L; i <= 100; i++){
        if(i & 0x1){
            if(N % i == 0){
                S = N/i - i/2;
                if(S >= 0){
                    for(int j = 0; j < i; j++) cout << S++ << ' ';
                    return 0;
                }
            }
        }else if(N % i != 0 && M % i == 0){
            S = N/i - i/2 + 1;
            if(S >= 0){
                for(int j = 0; j < i; j++) cout << S++ << ' ';
                return 0;
            }
        }
    }
    cout << -1;
    return 0;
}
