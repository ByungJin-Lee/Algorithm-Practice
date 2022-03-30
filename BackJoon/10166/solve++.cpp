#include <iostream>
#include <cstring>
#include <numeric>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int low, high, sum = 0;
    bool map[2001][2001];
    memset(map, true, sizeof(map));
    
    cin >> low >> high;
    for(int i = low; i <= high; i++){
        for(int j = low; j <= i; j++){
            int g = gcd(i, j), l = i/g, r = j /g;
            if(map[l][r]) {
                sum++;
                map[l][r] = false;
            }
        }
    }
    cout << sum;
    
    return 0;
}
