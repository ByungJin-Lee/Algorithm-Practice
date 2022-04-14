#include <iostream>
#include <cstring>
#include <queue>

#define P(p, z, x, y) {p.h + z, p.r + y, p.c + x}
#define Pos(p, z, x, y) map[p.h + z][p.r + y][p.c + x]

using namespace std;

typedef struct {int h,r,c;} POS3;

int N, M, H;
bool map[102][102][102];

int turnToMature(queue<POS3>& matures){
    int matured = 0;
    
    for(int i = 0, r = matures.size(); i < r; i++){
        auto p = matures.front();
        matures.pop();
        if(Pos(p, 0, 0, 1)){
            Pos(p, 0, 0, 1) = 0;
            matures.push(P(p,0,0,1));
            matured++;
        }
        if(Pos(p, 0, 0, -1)){
            Pos(p, 0, 0, -1) = 0;
            matures.push(P(p,0,0,-1));
            matured++;
        }
        if(Pos(p, 0, 1, 0)){
            Pos(p, 0, 1, 0) = 0;
            matures.push(P(p,0,1,0));
            matured++;
        }
        if(Pos(p, 0, -1, 0)){
            Pos(p, 0, -1, 0) = 0;
            matures.push(P(p,0,-1,0));
            matured++;
        }
        if(Pos(p, 1, 0, 0)){
            Pos(p, 1, 0, 0) = 0;
            matures.push(P(p,1,0,0));
            matured++;
        }
        if(Pos(p, -1, 0, 0)){
            Pos(p, -1, 0, 0) = 0;
            matures.push(P(p,-1,0,0));
            matured++;
        }
        
    }
    
    return matured;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    memset(map, 0, sizeof(map));
    
    cin >> M >> N >> H;
    
    int v, not_mature = 0, prev = 0, time = 0;
    queue<POS3> mature;
    
    for(int h = 1; h <= H; h++)
        for(int r = 1; r <= N; r++)
            for(int c = 1; c <= M; c++){
                cin >> v;
                not_mature += map[h][r][c] = v == 0;
                if(v == 1) mature.push({h, r, c});
            }
    
    if(not_mature == 0) {
        cout << 0;
        return 0;
    }
    
    while(mature.size()){
        prev = (int)mature.size();
        not_mature -= turnToMature(mature);
        time++;
    }
    
    cout << (not_mature == 0 ? time - 1 : -1);
    
    return 0;
}
