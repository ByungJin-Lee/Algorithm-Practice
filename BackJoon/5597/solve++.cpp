#include <iostream>
#include <cstring>

using namespace std;

int main(void){
    
    bool value[30];
    memset(value, 0, sizeof(value));
    
    int v;
    
    for(int i = 0; i < 28; i++){
        cin >> v;
        value[v - 1] = true;
    }
    
    for(int i = 0; i < 30; i++){
        if(value[i] == false){
            cout << i + 1 << '\n';
        }
    }
    
    
    
    return 0;
}
