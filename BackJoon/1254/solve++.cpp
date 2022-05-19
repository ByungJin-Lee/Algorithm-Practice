#include <iostream>

#define MAX_SIZE 50

using namespace std;

bool IsValid(char* in, int l, int r){
    while(l < r){
        if(in[l] != in[r]) return false;
        l++; r--;
    }
    return true;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    char in[MAX_SIZE + 1];
    cin >> in;
    
    int res = 0, len = 0;
    while(in[len] != 0) ++len;
    
    for(int i = 0; i < len; i++)
        if(IsValid(in, i, len - 1)) {
            res = len + i;
            break;
        }
    cout << res;
    return 0;
}
