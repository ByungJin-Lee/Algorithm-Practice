#include <iostream>
#include <algorithm>

#define P_THREE 25
#define P_FIVE 37
#define P_DAY 10

using namespace std;

bool IsRest[101];
int price[101][201];

int Forward(int limit, int day, int noc){
    if(day > limit) return 0;
    
    if(price[day][noc] != -1) return price[day][noc];
    
    if(IsRest[day]) return Forward(limit, day+1, noc);
    
    price[day][noc] = min({
        P_DAY + Forward(limit, day+1, noc),
        P_THREE + Forward(limit, day+3, noc+1),
        P_FIVE + Forward(limit, day+5, noc+2)
    });
    
    if(noc > 2) price[day][noc] = min(price[day][noc], Forward(limit, day+1, noc-3));
    
    return price[day][noc];
}


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    fill(&price[0][0], &price[100][201], -1);
    
    int N, M, day;
    cin >> N >> M;
    
    while(M-- != 0){
        cin >> day;
        IsRest[day] = true;
    }
    
    cout << Forward(N, 1, 0) * 1000;
    return 0;
}












//#include <cstring>
//#include <vector>
//#include <queue>
//#include <algorithm>
//
//#define PASS '='
//#define RAW '*'
//#define LOC '#'
//#define STA '@'
//#define END '!'
//#define MP(m, p) m[p.x][p.y]
//#define MDP(m, p, d1, d2) m[p.x+d1][p.y+d2]
//#define CP(p, i, d1, d2) {p.mine, i, p.x+d1, p.y+d2}
//
//using namespace std;
//
//typedef struct {int x, y;} Pos;
//typedef struct {bool own; Pos kP, dP;} Door;
//typedef struct {int prev, mine, x, y; } Footp;
//
//int R, C;
//char map[201][201];
//
//inline void Push(char m[201][201], queue<Footp>& q, vector<Footp>& v, Footp p){
//    q.push(p);
//    v.push_back(p);
//    MP(m, p) = LOC;
//}
//
//vector<Footp> bfs(Pos sta, char dest){
//    int idx = 1;
//    queue<Footp> q;
//    vector<Footp> f;
//    char m[201][201];
//    bool arrive = false;
//    copy(&map[0][0], &map[0][0] + (R * 201), &m[0][0]);
//
//    Push(m, q, f, {-1, 0, sta.x, sta.y});
//
//    while(!q.empty() && !arrive){
//        for(int i = 0, r = (int)q.size(); i < r; i++){
//            auto p = q.front();
//
//            if(MP(map, p) == dest) {
//                arrive = true;
//                idx = p.mine;
//                break;
//            }
//
//            if(MDP(m, p, 1, 0) != LOC) Push(m, q, f, CP(p, idx++, 1, 0));
//            if(MDP(m, p, 0, 1) != LOC) Push(m, q, f, CP(p, idx++, 0, 1));
//            if(MDP(m, p, -1, 0) != LOC) Push(m, q, f, CP(p, idx++, -1, 0));
//            if(MDP(m, p, 0, -1) != LOC) Push(m, q, f, CP(p, idx++, 0, -1));
//
//            q.pop();
//        }
//    }
//    vector<Footp> res;
//    //Record Footprints
//
//    if(arrive){
//        while(idx > -1){
//            auto p = f[idx];
//            res.push_back(p);
//            idx = p.prev;
//        }
//        reverse(res.begin(), res.end());
//    }
//    return res;
//}
//
//int main(void){
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//
//    Pos sta, end; Door doors[26];
//    memset(doors, 0, sizeof(doors));
//
//    cin >> R >> C;
//
//    for(int r = 0; r < R; r++){
//        cin >> map[r];
//        for(int c = 0; c < C; c++){
//            switch (map[r][c]) {
//                case STA: sta = {r, c}; break;
//                case END: end = {r, c}; break;
//                default: break;
//            }
//            if(c >= 'a' && c <= 'z') doors[c - 'a'].kP = {r, c};
//            else if(c >= 'A' && c <= 'Z') doors[c-'a'].dP = {r,c};
//        }
//    }
//
//    vector<Footp> foots = bfs(sta, END);
//
//    for(auto p : foots){
//        cout << MP(map, p) << ' ' << p.x + 1 << ' ' << p.y + 1  << '\n';
//    }
//
//    return 0;
//}
