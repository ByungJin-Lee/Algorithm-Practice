#include <iostream>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int sum = 0, v;
    
    for(int i = 0; i < 5; i++){
        cin >> v;
        sum += (v * v);
    }
    
    cout << sum % 10;
    
    return 0;
}
