#include <iostream>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    unsigned long long L, hashed = 0, I = 0, seq = 1;
    const unsigned int HASH_VAL = 1234567891;
    char chr[51];
    
    cin >> L >> chr;
    
    while(I < L){
        hashed = (hashed + ((chr[I] - 96) * seq)) % HASH_VAL;
        seq = (seq * 31) % HASH_VAL;
        I++;
    }
    
    cout << hashed;
    
    return 0;
}
