#include <iostream>
#include <algorithm>

using namespace std;

pair<int,int> GetPair(int D){
    pair<int,int> ps[31];
    ps[1] = make_pair(1, 0);
    ps[2] = make_pair(0, 1);
    for(int i = 3; i <= D; i++)
        ps[i] = make_pair(ps[i-1].first + ps[i-2].first, ps[i-1].second + ps[i-2].second);
    return ps[D];
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int D, K;
    
    cin >> D >> K;
    
    pair<int, int> pair = GetPair(D);
    
    int c1 = pair.first, c2 = pair.second, i = 1;
    
    while(true){
        int res = (K - c1 * i);
        if(res % c2 == 0){
            cout << i << '\n' << res / c2;
            break;
        }
        i++;
    }
    
    return 0;
}
