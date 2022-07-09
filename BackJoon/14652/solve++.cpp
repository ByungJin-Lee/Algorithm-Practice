#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int R, C, N;
    
    cin >> R >> C >> N;
    
    cout << N / C << ' ' <<  N % C;
    
    
    return 0;
}
