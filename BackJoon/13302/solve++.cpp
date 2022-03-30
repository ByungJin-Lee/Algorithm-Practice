#include <iostream>
#include <algorithm>

#define P_THREE 25
#define P_FIVE 37
#define P_DAY 10

using namespace std;

bool IsRest[101];
int price[101][201];

int Forward(int limit, int day, int noc){
    if(day > limit) return 0;
    
    if(price[day][noc] != -1) return price[day][noc];
    
    if(IsRest[day]) return Forward(limit, day+1, noc);
    
    price[day][noc] = min({
        P_DAY + Forward(limit, day+1, noc),
        P_THREE + Forward(limit, day+3, noc+1),
        P_FIVE + Forward(limit, day+5, noc+2)
    });
    
    if(noc > 2) price[day][noc] = min(price[day][noc], Forward(limit, day+1, noc-3));
    
    return price[day][noc];
}


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    fill(&price[0][0], &price[100][201], -1);
    
    int N, M, day;
    cin >> N >> M;
    
    while(M-- != 0){
        cin >> day;
        IsRest[day] = true;
    }
    
    cout << Forward(N, 1, 0) * 1000;
    return 0;
}
