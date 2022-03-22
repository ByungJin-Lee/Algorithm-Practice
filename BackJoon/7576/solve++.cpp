#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int R, C, V, E = 0, T = -1;
    
    queue<pair<int,int>> wells;
    
    bool farm[1002][1002];
    memset(farm, 0, sizeof(farm));
    
    cin >> C >> R;
    
    for(int r = 1; r <= R; r++){
        for(int c = 1; c <= C; c++){
            cin >> V;
            E += farm[r][c] = V == 0;
            if(V == 1) wells.push(make_pair(r, c));
        }
    }
    
    while(!wells.empty()){
        for(int i = 0, l = (int)wells.size(); i < l; i++){
            auto u = wells.front();
            
            if(farm[u.first-1][u.second]){
                farm[u.first-1][u.second] = false;
                wells.push(make_pair(u.first-1, u.second));
                E--;
            }
            if(farm[u.first+1][u.second]){
                farm[u.first+1][u.second] = false;
                wells.push(make_pair(u.first+1, u.second));
                E--;
            }
            if(farm[u.first][u.second-1]){
                farm[u.first][u.second-1] = false;
                wells.push(make_pair(u.first, u.second-1));
                E--;
            }
            if(farm[u.first][u.second+1]){
                farm[u.first][u.second+1] = false;
                wells.push(make_pair(u.first, u.second+1));
                E--;
            }
            wells.pop();
        }
        T++;
    }
    
    cout << (E == 0 ? T : -1);
    
    return 0;
}
