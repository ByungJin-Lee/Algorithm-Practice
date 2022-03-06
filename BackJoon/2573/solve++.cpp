#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

//Return Number Of Connected Component
int PassByOneYear(int R, int C, int HOI[][300]){
    int NumberOfCC = 0;
    for(int r = R - 2; r != 0; r--){
        for(int c = C - 2; c != 0; c--){
            if(HOI[r][c] == 0) continue;
            //UP
            if(HOI[r-1][c] == 0) HOI[r][c]--;
            //Down
            if(HOI[r+1][c] == 0) HOI[r][c]--;
            //Left
            if(HOI[r][c-1] == 0) HOI[r][c]--;
            //Right
            if(HOI[r][c+1] == 0) HOI[r][c]--;
            
            if(HOI[r][c] <= 0) HOI[r][c] = -1; //Lock Value, This Cycle
        }
    }
    
    
    //Free Lock Value and Count Connected Component
    bool nvisited[300][300];
    memset(nvisited, true, sizeof(nvisited));
    for(int r = R - 2; r != 0; r--){
        for(int c = C - 2; c != 0; c--) {
            if(HOI[r][c] == -1) HOI[r][c] = 0;
            
            if(HOI[r][c] > 0 && nvisited[r][c]){
                NumberOfCC++;
                nvisited[r][c] = false;
                queue<pair<int, int>> q;
                q.push(make_pair(r, c));
                
                while(!q.empty()){
                    pair<int, int> p = q.front();
                    q.pop();
                    
                    //UP
                    if(HOI[p.first-1][p.second] > 0 && nvisited[p.first-1][p.second]){
                        nvisited[p.first-1][p.second] = false;
                        q.push(make_pair(p.first-1, p.second));
                    }
                    //Down
                    if(HOI[p.first+1][p.second] > 0 && nvisited[p.first+1][p.second]){
                        nvisited[p.first+1][p.second] = false;
                        q.push(make_pair(p.first+1, p.second));;
                    }
                    //Left
                    if(HOI[p.first][p.second-1] > 0 && nvisited[p.first][p.second-1]){
                        nvisited[p.first][p.second-1] = false;
                        q.push(make_pair(p.first, p.second-1));;
                    }
                    //Right
                    if(HOI[p.first][p.second+1] > 0 && nvisited[p.first][p.second+1]){
                        nvisited[p.first][p.second+1] = false;
                        q.push(make_pair(p.first, p.second+1));;
                    }
                }
            }
        }
    }
    return NumberOfCC;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int R, C, HightOfIceberg[300][300], PassedYear = 0, ret;
    cin >> R >> C;
    
    for(int i = 0; i < R; i++)
        for(int j = 0; j < C; j++) cin >> HightOfIceberg[i][j];
    
    while((ret = PassByOneYear(R, C, HightOfIceberg)) == 1) PassedYear++;
    
    if(ret > 0) cout << PassedYear + 1;
    else cout << 0;
    
    return 0;
}
