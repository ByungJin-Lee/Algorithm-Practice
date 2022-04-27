#include <iostream>
#include <algorithm>
#define NONE 100000

using namespace std;

int target;

int Forward(int step, long long val){
    if(val == target) return step;
    
    if(val > target) return NONE;
    
    return min(Forward(step+1, val * 2), Forward(step+1, val * 10 + 1));
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int init;
    
    cin >> init >> target;
    
    int res = Forward(0, init);
    
    cout << (res == NONE ? -1 : res + 1);

    return 0;
}
