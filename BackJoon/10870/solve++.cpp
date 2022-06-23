#include <iostream>

using namespace std;

int main(void){
    int value[21];
    
    value[0] = 0; value[1] = 1;
    for(int i = 2; i < 21; i++) value[i] = value[i-1] + value[i-2];
    
    int sel;
    
    cin >> sel;
    
    cout << value[sel];
    
    return 0;
}
