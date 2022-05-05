#include <iostream>
#include <cmath>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int NumOfSong, Avg;
    
    cin >> NumOfSong >> Avg;
    
    double top = NumOfSong * Avg;
    
    while(((int)ceil(top/NumOfSong)) == Avg) top--;
    
    cout << top+1;

    return 0;
}
