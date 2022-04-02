#include <iostream>
#include <algorithm>

using namespace std;

unsigned int Values[1000000];

bool BinarySearch(int low, int high, unsigned int value){
    int m;
    while(low <= high){
        m = (low + high) / 2;
        if(Values[m] == value) return true;
        if(Values[m] > value) high = m - 1;
        else low = m + 1;
    }
    return false;
}

void Forward(unsigned int X, unsigned int N){
    unsigned int I, M;
    
    X *= 10000000;
    M = X / 2;
    
    for(I = 0; I < N; I++) cin >> Values[I];
    
    sort(Values, Values + N);
    
    I = 0;
    while (I < N && Values[I] <= M) {
        if(BinarySearch(I+1, N-1, X - Values[I])){
            cout << "yes " << Values[I] << ' ' << X - Values[I] << '\n';
            return;
        }
        I++;
    }
    cout << "danger\n";
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    unsigned int X, N;
    
    while(true){
        cin >> X >> N;
        if(cin.eof() == true) break;
        Forward(X, N);
    }
    
    return 0;
}
