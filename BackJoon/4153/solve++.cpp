#include <iostream>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int value[3];
    
    while(1){
        cin >> value[0] >> value[1] >> value[2];
        
        if(value[0] == 0 && value[1] == 0 && value[2] == 0)
            break;
        
        sort(value, value + 3);
        
        if(value[2] * value[2] == value[1] * value[1] + value[0] * value[0])
            cout << "right\n";
        else
            cout << "wrong\n";
    }
    
    return 0;
}
