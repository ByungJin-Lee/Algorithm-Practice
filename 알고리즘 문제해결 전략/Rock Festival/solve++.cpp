//록 페스티벌 문제
#include <iostream>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T, N, L, Min, Cost[1001];
    double minCost;
    Cost[0] = 0;
    cin >> T;
    while(T-- != 0){
        minCost = 100000;
        cin >> N >> L;
        for(int i = 1; i <= N; Cost[i] += Cost[i-1], i++) cin >> Cost[i];
        
        while(L <= N){
            Min = 100000;
            for(int f = L, b = 0; f <= N ; f++, b++)
                Min = min(Min, Cost[f] - Cost[b]);
            minCost = min(minCost, Min / (double)L);
            L++;
        }
        cout << minCost;
    }
    return 0;
}
