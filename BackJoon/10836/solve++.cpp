#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int M, N, L, House[1400];
    string back = "";
    unsigned char E[1400];
    fill(House, House + 1400, 1);
    cin >> M >> N;
    L = 2 * M - 1;
    while(N-- != 0){
        for(int i = 0, q = 0, t; i < 3; i++){
            cin >> t;
            memset(&E[q+1], i, sizeof(unsigned char) * t);
            q += t;
        }
        for(int i = 0; i <= L; i+=7) {
            House[i] += E[i];
            House[i+1] += E[i+1];
            House[i+2] += E[i+2];
            House[i+3] += E[i+3];
            House[i+4] += E[i+4];
            House[i+5] += E[i+5];
            House[i+6] += E[i+6];
        }
    }
    
    for(int i = M + 1; i <= L; i++) back += " " + to_string(House[i]);
    
    for(int i = 0; i < M; i++) cout << House[M-i] << back << '\n';
    
    return 0;
}
