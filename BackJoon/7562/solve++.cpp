#include <iostream>
#include <queue>

using namespace std;

bool unvisited[300][300];

int e;

int CalcMinMovement(int x, int y);

inline void IsPushQue(queue<pair<int,int>>& q, int x, int y){
    if(x >= 0 && y >= 0 && x < e && y < e && unvisited[y][x]){
        q.push(make_pair(x, y));
        unvisited[y][x] = false;
    }
}


int CalcMinMovement(int x, int y, int ex, int ey){
    bool IsContinue = true;
    queue<pair<int,int>> q;
    q.push(make_pair(x, y));
    int move = 0;
    while(IsContinue && !q.empty()){
        for(int _i = 0, r = (int)q.size(); _i < r; _i++){
            pair<int, int>& p = q.front();
            
            if(p.first == ex && p.second == ey) {
                IsContinue = false;
                break;
            }
            
            IsPushQue(q, p.first + 2, p.second - 1);
            IsPushQue(q, p.first + 2, p.second + 1);
            
            IsPushQue(q, p.first + 1, p.second + 2);
            IsPushQue(q, p.first - 1, p.second + 2);
            
            IsPushQue(q, p.first - 2, p.second + 1);
            IsPushQue(q, p.first - 2, p.second - 1);
            
            IsPushQue(q, p.first - 1, p.second - 2);
            IsPushQue(q, p.first + 1, p.second - 2);
            
            q.pop();
        }
        move++;
    }
    return move - 1;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, sx, sy, ex, ey;
    
    cin >> N;
    
    while(N-- != 0){
        cin >> e >> sy >> sx >> ey >> ex;
        memset(unvisited, true, sizeof(unvisited));
        cout << CalcMinMovement(sx, sy, ex, ey) << '\n';
    }
    
    return 0;
}
