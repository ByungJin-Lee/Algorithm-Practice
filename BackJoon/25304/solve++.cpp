#include <iostream>

using namespace std;

int main() {
    int T, N, C = 0;
    
    cin >> T >>  N;
    
    for(int i = 0, p, count; i < N; i++){
        cin >> p >> count;
        C += (p * count);
    }
    cout << (T == C ? "Yes" : "No");
    return 0;
}
