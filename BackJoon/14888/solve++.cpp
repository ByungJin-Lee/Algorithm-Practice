#include <iostream>
#include <limits>

int values[11], opera[10],
     N, mx = INT_MIN, mn = INT_MAX;

inline int calc(int i, int type, int score){
    int& v = values[i+1];
    switch (type) {
        case 0: return score + v;
        case 1: return score - v;
        case 2: return score * v;
        case 3: return score / v;
    }
    return 0;
}

void Forward(int i, int score){
    if(i == N - 1){
        if(score > mx) mx = score;
        if(score < mn) mn = score;
        return;
    }
    for(int j = 0, type; j < N - 1; j++){
        if(opera[j] == -1) continue;
        type = opera[j];
        opera[j] = -1;
        Forward(i+1, calc(i, type, score));
        opera[j] = type;
    }
}

using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    
    for(int i = 0; i < N; i++) cin >> values[i];
    
    for(int i = 0, j = 0, count; i < 4; i++){
        cin >> count;
        for(; count > 0; count--) opera[j++] = i;
    }
    Forward(0, values[0]);
    
    cout << mx << '\n' << mn;

    return 0;
}
