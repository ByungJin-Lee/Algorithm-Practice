#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

#define InScope(r, c, er, ec) (r >= 0 && c >= 0&& r < er && c < ec)

using namespace std;

vector<pair<int,int>> GetVertexs(char map[50][51], bool land[50][50], int R, int C){
    vector<pair<int,int>> vec;
    for(int r = 0; r < R; r++){
        for(int c = 0; c < C; c++){
            if(map[r][c] == 'W') continue;
            land[r][c] = true;
            vec.push_back(make_pair(r, c));
        }
    }
    return vec;
}

int bfs(bool land[50][50], pair<int,int> v, int R, int C){
    int depth = 0;
    bool unvisited[50][50];
    copy(&land[0][0], &land[0][0] + 2500, &unvisited[0][0]);
    
    queue<pair<int, int>> q;
    q.push(v);
    unvisited[v.first][v.second] = false;
    
    while(!q.empty()){
        int l = (int)q.size();
        for(int i = 0; i < l; i++){
            auto p = q.front();
            q.pop();
    
            if(InScope(p.first+1, p.second, R, C) && unvisited[p.first+1][p.second]){
                unvisited[p.first+1][p.second] = false;
                q.push(make_pair(p.first+1, p.second));
            }
            if(InScope(p.first-1, p.second, R, C) && unvisited[p.first-1][p.second]){
                unvisited[p.first-1][p.second] = false;
                q.push(make_pair(p.first-1, p.second));
            }
            if(InScope(p.first, p.second+1, R, C) && unvisited[p.first][p.second+1]){
                unvisited[p.first][p.second+1] = false;
                q.push(make_pair(p.first, p.second+1));
            }
            if(InScope(p.first, p.second-1, R, C) && unvisited[p.first][p.second-1]){
                unvisited[p.first][p.second-1] = false;
                q.push(make_pair(p.first, p.second-1));
            }
        }
        depth++;
    }
    
    return depth-1;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int R, C;
    bool land[50][50];
    memset(land, false, sizeof(land));
    
    cin >> R >> C;
    
    char map[50][51];
    for(int i = 0; i < R; i++) cin >> map[i];
    
    vector<pair<int,int>> vertexs = GetVertexs(map, land, R, C);
    
    int max = 0, temp;
    for(pair<int,int>& p : vertexs){
        temp = bfs(land, p, R, C);
        if(max <= temp) max = temp;
    }
    cout << max;
    
    return 0;
}
