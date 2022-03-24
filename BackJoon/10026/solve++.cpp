#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

char pixels[102][102];
bool unvisited[102][102];

bool UnNormalCmp(char& lhs, char& rhs){ return rhs == 'R' || rhs == 'G'; }
bool NormalCmp(char& lhs, char& rhs){ return lhs == rhs; }

int bfs(int r, int c, bool (*Compare)(char& lhs, char& rhs)){
    queue<pair<int, int>> qu;
    qu.push(make_pair(r, c));
    unvisited[r][c] = false;
    char tar = pixels[r][c];
    int count = 0;
    while(!qu.empty()){
        auto p = qu.front();
        if(Compare(tar, pixels[p.first+1][p.second]) && unvisited[p.first+1][p.second]){
            unvisited[p.first+1][p.second] = false;
            qu.push(make_pair(p.first+1, p.second));
        }
        if(Compare(tar, pixels[p.first][p.second+1]) && unvisited[p.first][p.second+1]){
            unvisited[p.first][p.second+1] = false;
            qu.push(make_pair(p.first, p.second+1));
        }
        if(Compare(tar, pixels[p.first-1][p.second]) && unvisited[p.first-1][p.second]){
            unvisited[p.first-1][p.second] = false;
            qu.push(make_pair(p.first-1, p.second));
        }
        if(Compare(tar, pixels[p.first][p.second-1]) && unvisited[p.first][p.second-1]){
            unvisited[p.first][p.second-1] = false;
            qu.push(make_pair(p.first, p.second-1));
        }
        count++;
        qu.pop();
    }
    return count;
}

int run(int N, bool isNormal){
    memset(unvisited, 1, sizeof(unvisited));
    int count = 0;
    for(int r = 1; r <= N; r++){
        for(int c = 1; c <= N; c++){
            if(unvisited[r][c]){
                count++;
                if(isNormal){
                    bfs(r,c, NormalCmp);
                }else{
                    bfs(r,c, (pixels[r][c] == 'B' ? NormalCmp : UnNormalCmp));
                }
            }
        }
    }
    return count;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    
    cin >> N;
    
    for(int i = 1; i <= N; i++) cin >> &pixels[i][1];
    
    cout << run(N, true) << ' ' << run(N, false);
    
    return 0;
}
