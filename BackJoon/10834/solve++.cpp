#include <iostream>
#include <numeric>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int NumberOfBelt, cycle, left, right, type, multiply, lc;
    bool direct;
    
    cin >> NumberOfBelt;
    //First
    cin >> multiply >> cycle >> direct;
    
    while(--NumberOfBelt != 0){
        cin >> left >> right >> type;
        direct = type == 0 ? direct : !direct;
        lc = lcm(cycle, left);
        multiply *= (lc / cycle);
        cycle = right * (lc / left);
    }
    cout << direct << ' ' << cycle / multiply;
    return 0;
}
