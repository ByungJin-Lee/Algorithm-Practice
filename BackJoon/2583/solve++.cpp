#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>

#define InScope(lhs, rhs, el, er) (lhs >= 0 && lhs < el) && (rhs >= 0 && rhs < er)

using namespace std;

int AreaBFS(bool CanPassed[][100], int unsorted[], const int R, const int C){
    int _i = 0;
    
    for(int _r = 0; _r < R; _r++){
        for(int _c = 0; _c < C; _c++){
            if(!CanPassed[_r][_c]) continue;
            
            int area = 1;
            
            queue<pair<int, int>> que;
            que.push(make_pair(_r, _c));
            CanPassed[_r][_c] = false;
            
            while(!que.empty()){
                pair<int, int>& p = que.front();
                if(InScope(p.first + 1, p.second, R, C) && CanPassed[p.first + 1][p.second]){
                    que.push(make_pair(p.first + 1, p.second));
                    CanPassed[p.first+1][p.second] = false;
                    area++;
                }
                if(InScope(p.first - 1, p.second, R, C) && CanPassed[p.first - 1][p.second]){
                    que.push(make_pair(p.first - 1, p.second));
                    CanPassed[p.first-1][p.second] = false;
                    area++;
                }
                if(InScope(p.first, p.second + 1, R, C) && CanPassed[p.first][p.second + 1]){
                    que.push(make_pair(p.first, p.second + 1));
                    CanPassed[p.first][p.second + 1] = false;
                    area++;
                }
                if(InScope(p.first, p.second - 1, R, C) && CanPassed[p.first][p.second - 1]){
                    que.push(make_pair(p.first, p.second - 1));
                    CanPassed[p.first][p.second - 1] = false;
                    area++;
                }
                que.pop();
            }
            unsorted[_i++] = area;
        }
    }
    
    sort(unsorted, unsorted + _i);
    return _i;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int R, C, K;
    
    bool CanPassed[100][100];
    memset(CanPassed, true, sizeof(CanPassed));
    
    cin >> R >> C >> K;
    
    int sr, sc, er, ec;
    
    while(K-- != 0){
        cin >> sc >> sr >> ec >> er;
        for(int _r = sr; _r < er; _r++)
            for(int _c = sc; _c < ec; _c++) CanPassed[_r][_c] = false;
    }
    
    int areas[100], res = AreaBFS(CanPassed, areas, R, C);
    
    cout << res << '\n';
    
    for(int i = 0; i < res; i++)
        cout << areas[i] << ' ';
        
    
    return 0;
}
