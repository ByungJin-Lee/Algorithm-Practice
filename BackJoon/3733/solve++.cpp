#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b;
    while(cin >> a >> b){
        cout << b / (a+1) << '\n';
    }
    
    
    return 0;
}
