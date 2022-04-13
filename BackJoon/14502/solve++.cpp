#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

unsigned int map[10][10];
bool nvisited[10][10];
pair<int, int> zero[64], virus[64];

int N, M, Z = 0, V = 0;

#define CanVisit(p, v1, v2) nvisited[p.first + v1][p.second + v2] && map[p.first + v1][p.second + v2] == 0
#define Visit(p, v1, v2) nvisited[p.first + v1][p.second + v2] = false; \
    q.push(make_pair(p.first + v1, p.second + v2))

int spread(){
    int count = 0;
    queue<pair<int, int>> q;
    memset(nvisited, 1, sizeof(nvisited));
    
    for(int i = 0; i < V; i++) {
        pair<int, int>& v = virus[i];
        q.push(v);
    }
    
    while(!q.empty()){
        pair<int, int>& p = q.front();
        q.pop();
        if(CanVisit(p, 1, 0)){
            Visit(p, 1, 0);
        }
        if(CanVisit(p, 0,  1)){
            Visit(p, 0, 1);
        }
        if(CanVisit(p, -1,  0)){
            Visit(p, -1, 0);
        }
        if(CanVisit(p, 0,  -1)){
            Visit(p, 0, -1);
        }
        count++;
    }
    return count - V;
}

int Forward(int s){
    if(s == 0) return spread();
    
    int r, victim = 99999;
    
    for(int i = 0; i < Z; i++){
        r = zero[i].first;
        if(r == 0) continue;
        map[r][zero[i].second] = 1;
        zero[i].first = 0;
        victim = min(victim, Forward(s - 1));
        map[r][zero[i].second] = 0;
        zero[i].first = r;
    }
    
    return victim;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    fill(&map[0][0], &map[9][10], 1);

    cin >> N >> M;

    for(int r = 1; r <= N; r++)
        for(int c = 1; c <= M; c++){
            cin >> map[r][c];
            if(map[r][c] == 0) zero[Z++] = make_pair(r, c);
            else if(map[r][c] == 2) virus[V++] = make_pair(r, c);
        }
    
    cout << Z - 3 - Forward(3);
    
    return 0;
}
