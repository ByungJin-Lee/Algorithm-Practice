#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool Satisfied(vector<int>& trees, const int height, const int required){
    long long sum = 0;
    for(int& t : trees){
        if(t <= height) continue;
        sum += (t - height);
    }
    return sum >= required;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int NumOfTree, Required;
    
    cin >> NumOfTree >> Required;
    
    vector<int> trees;
    for(int i = 0, _h; i < NumOfTree; i++){
        cin >> _h;
        trees.push_back(_h);
    }
    
    int l = 1, r = 1000000000, m, res = 0;
    
    while(l <= r){
        m = (l + r) / 2;
        if(Satisfied(trees, m, Required)) {
            l = m + 1;
            res = m;
        }
        else r = m - 1;
    }
    cout << res;
    
    return 0;
}
