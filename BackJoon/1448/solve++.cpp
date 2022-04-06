#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    //가장 긴 변이 c 가 다른 두 변의 합보다 작아야된다. c < a + b
    int N, straws[1000000], res = -1;
    
    cin >> N;
    for(int i = 0; i < N; i++) cin >> straws[i];
    sort(straws, straws + N);
    
    for(int i = N - 1; i > 1; i--){
        if(straws[i] < straws[i-1] + straws[i-2]){
            res = straws[i] + straws[i-1] + straws[i-2];
            break;
        }
    }
    
    cout << res;
    return 0;
}
