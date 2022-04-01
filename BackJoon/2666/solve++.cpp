#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

int seq[20], len;

int r(int i, int score, int x, int y){
    if (i == len) return score;

    int t = seq[i];

    return min(r(i + 1, score + abs(t - x), t, y), r(i + 1, score + abs(t - y), x, t));
}


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int d1, d2, _;

    cin >> _ >> d1 >> d2 >> len;

    for (int i = 0; i < len; i++) cin >> seq[i];

    cout << r(0, 0, d1, d2);

    return 0;
}
