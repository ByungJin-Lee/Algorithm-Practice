#include <iostream>

using namespace std;

inline int count(int lhs, int rhs){
    int l = lhs / rhs;
    return lhs % rhs == 0 ? l : l + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t, a, b, pa, pb;
    
    cin >> t >> a >> b >> pa >> pb;
    
    int left = count(a, pa), right = count(b, pb);
    
    if(left < right) left = right;
    
    cout << t - left;
    
    
    return 0;
}
