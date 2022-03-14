#include <iostream>
#include <cmath>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    bool numbers[1000001];
    int s, l;
    fill(numbers, numbers+1000001, true);
    numbers[0] = numbers[1] = false;
    
    cin >> s >> l;
    
    for(int n = 2, r = sqrt(l); n <= r; n++){
        for(int d = max(2, r / n); d * n <= l; d++) numbers[d * n] = false;
    }
    
    for(int i = s; i <= l; i++){
        if(numbers[i]) cout << i << '\n';
    }
    
    
    return 0;
}
