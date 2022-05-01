#include <iostream>
#include <queue>
#include <cstring>

#define MAX_SIZE 51

using namespace std;

int NumOfParty, NumOfPerson;

bool party[MAX_SIZE][MAX_SIZE];

void Spread(int pi){
    queue<int> victims;
    
    for(int i = 1; i <= NumOfParty; i++){
        if(!party[i][pi] || party[i][0]) continue;
        party[i][0] = true;

        for(int k = 1; k <= NumOfPerson; k++){
            if(k == pi) continue;
            if(party[i][k]) victims.push(k);
        }
    }
    
    while(!victims.empty()){
        Spread(victims.front());
        victims.pop();
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    bool truth[MAX_SIZE];
    int NumOfKnow;
    
    memset(party, 0, sizeof(party));
    memset(truth, 0, sizeof(truth));
    
    cin >> NumOfPerson >> NumOfParty >> NumOfKnow;
    
    for(int i = 0, v; i < NumOfKnow; i++){
        cin >> v; truth[v] = true;
    }
    
    for(int i = 1, v, p; i <= NumOfParty; i++){
        cin >> v;
        for(int j = 0; j < v; j++){
            cin >> p; party[i][p] = true;
        }
    }
    
    for(int i = 1; i <= NumOfPerson; i++)
        if(truth[i]) Spread(i);
    
    int count = 0;
    for(int i = 1; i <= NumOfParty; i++)
        if(!party[i][0]) count++;
    cout << count;
    
    return 0;
}
