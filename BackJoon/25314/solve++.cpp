#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    
    cin >> N;
    
    for(int i = 1, c = N / 4; i < c; i++){
        cout << "long" << ' ';
    }
    cout << "long int";
    
    return 0;
}
