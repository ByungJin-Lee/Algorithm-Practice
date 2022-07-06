#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int a, b, value[5];
    
    cin >> a >> b;
    
    a *= b;
    
    for(int i = 0; i < 5; i++){
        cin >> value[i];
        value[i] -= a;
    }
    
    for(int i = 0;i < 5; i++){
        cout << value[i] << ' ';
    }
    
    
    
    return 0;
}
