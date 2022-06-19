#include <iostream>
#include <string>

using namespace std;

int main(void){
    
    int total = 0;
    
    for(int i = 0, v; i < 5; i++){
        cin >> v;
        total += v;
    }
    
    cout << total;
    
    return 0;
}
