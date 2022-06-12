#include <iostream>

using namespace std;

int main(void){
    int minT = 0, manT = 0, s;
    
    for(int n = 0; n < 4; n++){
        cin >> s;
        minT += s;
    }
    
    for(int n = 0; n < 4; n++){
        cin >> s;
        manT += s;
    }
    
    cout << (minT >= manT ? minT : manT);
    
    return 0;
}
