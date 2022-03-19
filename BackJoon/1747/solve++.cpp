#include <iostream>
#include <cmath>
#include <cstring>
#include <string>

using namespace std;

inline bool IsPalindrome(int num){
    string numStr = to_string(num);
    int len = (int)numStr.length();
    for(int i = 0, r = len/2; i < r; i++)
        if(numStr[i] != numStr[len - i - 1]) return false;
    return true;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, res = 0;
    
    cin >> N;
    
    bool prime[1000001];
    memset(prime, 1, sizeof(prime));
    prime[0] = prime[1] = false;
    
    for(int i = 2; i <= 1000; i++)
        for(int j = 2; i * j <= 1000000; j++) prime[i * j] = false;
    
    for(int i = N; i <= 1000000 && res == 0; i++)
        if(prime[i] && IsPalindrome(i)) res = i;
    
    cout << (res ? res : 1003001);
    
    return 0;
}
