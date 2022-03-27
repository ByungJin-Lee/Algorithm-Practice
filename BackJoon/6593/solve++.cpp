#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

#define POS(m, p) m[p.z][p.r][p.c]
#define DPOS(m, p, v1, v2, v3) m[p.z + v1][p.r + v2][p.c+ v3]
#define GPOS(p, v1, v2, v3) {p.z+v1, p.r+v2, p.c+v3}

typedef struct {int z, r, c; } Pos3D;

int bfs3d(bool m[32][32][32], Pos3D& start, Pos3D& end){
    int move = 0;
    queue<Pos3D> q;
    q.push(start);
    POS(m, start) = false;
    
    while(!q.empty()){
        for(int i = 0, r = (int)q.size();  i < r; i++){
            Pos3D& p = q.front();
            if(p.z == end.z && p.r == end.r && p.c == end.c) return move;
            if(DPOS(m, p, 0, 1, 0)){
                DPOS(m, p, 0, 1, 0) = false;
                q.push(GPOS(p, 0, 1, 0));
            }
            if(DPOS(m, p, 0, 0, 1)){
                DPOS(m, p, 0, 0, 1) = false;
                q.push(GPOS(p, 0, 0, 1));
            }
            if(DPOS(m, p, 0, -1, 0)){
                DPOS(m, p, 0, -1, 0) = false;
                q.push(GPOS(p, 0, -1, 0));
            }
            if(DPOS(m, p, 0, 0, -1)){
                DPOS(m, p, 0, 0, -1) = false;
                q.push(GPOS(p, 0, 0, -1));
            }
            if(DPOS(m, p, 1, 0, 0)){
                DPOS(m, p, 1, 0, 0) = false;
                q.push(GPOS(p, 1, 0, 0));
            }
            if(DPOS(m, p, -1, 0, 0)){
                DPOS(m, p, -1, 0, 0) = false;
                q.push(GPOS(p, -1, 0, 0));
            }
            q.pop();
        }
        move++;
    }
    return -1;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    bool building[32][32][32];
    int R, C, H;
    Pos3D start, end;
    
    while(true){
        cin >> H >> R >> C;
        if(R + C + H == 0) break;
        
        memset(building, false, sizeof(building));
        char temp[31];
        
        for(int layor = 1; layor <= H; layor++){
            for(int row = 1; row <= R; row++){
                cin >> temp;
                for(int col = 0; col < C; col++){
                    building[layor][row][col+1] = temp[col] != '#';
                    if(temp[col] == 'S') start = {layor, row, col+1};
                    else if(temp[col] == 'E') end = {layor, row, col+1};
                }
            }
        }
        int res = bfs3d(building, start, end);
        if(res != -1) cout << "Escaped in " << res << " minute(s).\n";
        else cout << "Trapped!\n";
    }
    
    return 0;
}
