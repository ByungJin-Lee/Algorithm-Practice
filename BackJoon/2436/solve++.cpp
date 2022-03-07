#include <iostream>
#include <cmath>
#include <numeric>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    unsigned int gc, lc, stand, sum;
    
    cin >> gc >> lc;
    stand = lc / gc;
    
    pair<int, int> mp = make_pair(1, stand);
    sum = 1 + stand;
    for(int x = 2, r = sqrt(stand), y; x <= r; x++){
        if(stand % x == 0){
            y = stand / x;
            if(gcd(y, x) == 1){
                if(x + y < sum){
                    sum = x + y;
                    mp.first = x;
                    mp.second = y;
                }
            }
        }
    }
    
    cout << mp.first * gc << ' ' << mp.second * gc;
    return 0;
}
