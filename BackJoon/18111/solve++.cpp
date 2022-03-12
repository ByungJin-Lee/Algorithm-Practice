#include <iostream>
#include <cstring>

#define TIME_RM 2
#define TIME_CR 1

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    unsigned short World[500][500], minHg = 256, maxHg = 0, h;
    unsigned int R, C, B, A, T, TL, TB = 0, FB = 0, Ly[257], r, c;
    memset(Ly, 0, sizeof(Ly));
    cin >> R >> C >> B;
    A = R * C;
    
    r = R;
    while(r-- != 0){
        c = C;
        while(c-- != 0){
            cin >> h;
            if(minHg > h) minHg = h;
            if(maxHg < h) maxHg = h;
            World[r][c] = h;
        }
    }
    
    //Ly 완성
    r = R;
    while(r-- != 0){
        c = C;
        while(c-- != 0){
            h = World[r][c] - minHg;
            TB += h;
            for(int i = 0; i < h; i++) Ly[i + minHg]++;
        }
    }
    //Remove TB
    T = TB * TIME_RM;
    TL = minHg;
    TB -= Ly[minHg];
    FB += (A - Ly[minHg]);
    //Check All
    for(int i = minHg + 1, t; i <= maxHg; i++){
        //Need to Remove;
        t = FB * TIME_CR + TB * TIME_RM;
        
        if(T >= t && FB <= B + TB){
            T = t;
            TL = i;
        }
        TB -= Ly[i];
        FB += (A - Ly[i]);
    }
    
    cout << T << ' ' << TL;
    
    return 0;
}
