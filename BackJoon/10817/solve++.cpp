#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int values[3];
    
    cin >> values[0] >> values[1] >> values[2];
    
    sort(values, values + 3);
    
    cout << values[1];
    
    return 0;
}
