#include <iostream>
#include <cstring>

#define MAX_SIZE 2187

using namespace std;

int paper[MAX_SIZE][MAX_SIZE], cnt[3];

inline bool CheckType(int sx, int sy, int len){
    int type = paper[sy][sx];
    for(int y = sy, yr = sy + len; y < yr; y++)
        for(int x = sx, xr = sx + len; x < xr; x++)
            if(paper[y][x] != type) return false;
    return true;
}

void r(int sx, int sy, int len){
    if(len == 1 || CheckType(sx, sy, len)){
        cnt[paper[sy][sx] + 1]++;
        return;
    }
    
    int d_len = len / 3;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++)
            r(sx + d_len * i, sy + d_len * j, d_len);
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int len;
    cnt[0] = cnt[1] = cnt[2] = 0;
    cin >> len;
    for(int i = 0; i < len; i++)
        for(int j = 0; j < len; j++) cin >> paper[i][j];
    r(0, 0, len);
    cout << cnt[0] << '\n' << cnt[1] << '\n' << cnt[2];
   
    return 0;
}
