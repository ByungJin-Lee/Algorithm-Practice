#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, L;
    
    cin >> N >> L;
    
    bool betweens[2000];
    memset(betweens, 0, sizeof(betweens));
    
    vector<int> brokens;
    int spoted;
    for(int i = 0; i < N; i++) {
        cin >> spoted;
        brokens.push_back(spoted);
    }
    sort(brokens.begin(), brokens.end());

    int required = 0;
    for(int& broken : brokens){
        int left = (broken - 1) * 2, right = (broken - 1) * 2 + 1;
        if(betweens[left] && betweens[right]) continue;
        required++;
        for(int i = betweens[left] ? right : left, r = min(2000, i + 2 * L); i < r; i++)
            betweens[i] = true;
    }

    cout << required;
    return 0;
}
