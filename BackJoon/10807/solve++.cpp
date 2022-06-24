#include <iostream>

using namespace std;

int main(void){
    int value[100], len, tar, count = 0;
    
    cin >> len;
    
    for(int i = 0; i < len; i++) cin >> value[i];
    
    cin >> tar;
    
    for(int i = 0; i < len; i++) if(tar == value[i]) count++;
    
    cout << count;
    
    return 0;
}
