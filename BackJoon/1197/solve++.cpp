#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

typedef struct {int v1, v2, cost;} Edge;

bool incl[10001];

bool sort_edge(Edge& lhs, Edge& rhs){
    return lhs.cost < rhs.cost;
}

inline int Connect(list<Edge>::iterator it, list<Edge>& edges){
    incl[it->v1] = incl[it->v2] = true;
    edges.erase(it);
    return it->cost;
}

inline int GetUseable(Edge& e){
    if(incl[e.v1] && incl[e.v2]) return 0;
    
    if(incl[e.v1] || incl[e.v2]) return 1;
    
    return 2;
}

list<Edge>::iterator GetNextMinimum(list<Edge>& edges){
    auto itor = edges.begin(), end = edges.end();
    while(itor != end){
        int type = GetUseable(*itor);
        if(type == 1) break;
        if(type == 0) itor = edges.erase(itor);
        else itor++;
    }
    return itor;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int NOV, NOE, v1, v2, cost, NOC = 2;
    cin >> NOV >> NOE;
    
    if(NOV == 1){
        cout << 0;
        return 0;
    }
    
    list<Edge> edges;
    long long Cost = 0;
    
    while(NOE-- != 0){
        cin >> v1 >> v2 >> cost;
        if(v1 == v2) continue;
        edges.push_back({v1, v2, cost});
    }
    
    edges.sort(sort_edge);
    
    auto itor = edges.begin();
    Cost += Connect(itor, edges);
    
    while(NOC < NOV){
        auto itor = GetNextMinimum(edges);
        if(itor == edges.end()) break;
        Cost += Connect(itor, edges);
        NOC++;
    }
    
    cout << Cost;
    
    return 0;
}
