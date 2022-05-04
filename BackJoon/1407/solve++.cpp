#include <iostream>

using namespace std;

unsigned long long CountMultiple(unsigned long long n){
    unsigned long long count = n;
    for(unsigned long long num = 2; num <= n; num *= 2)
        count += ((n/num) * (num / 2) );
    return count;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    unsigned long long A, B;
    
    cin >> A >> B;
    
    cout << CountMultiple(B) - CountMultiple(A-1);

    return 0;
}
