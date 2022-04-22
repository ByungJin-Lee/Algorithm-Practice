#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int PeriodOfSummer, RequiredTime, BlankSpot, Price;
    
    cin >> PeriodOfSummer >> RequiredTime >> BlankSpot >> Price;
    
    cout << Price * BlankSpot * ((PeriodOfSummer-1) / RequiredTime);
    
    
    return 0;
}
