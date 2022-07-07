#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int a,b,c,d,e;
    
    cin >> a >> b >> c >> d >> e;
    
    if(a < b) b = a;
    
    if(b < c) c = b;
    
    if(d < e) e = d;
    
    cout << c + e - 50;
    
    return 0;
}
