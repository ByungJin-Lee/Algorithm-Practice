#include <iostream>
#include <algorithm>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    
    set<string> no_heard;
    vector<string> no_heard_watched;
    
    cin >> N >> M;
    
    string input_name;
    for(int i = 0; i < N; i++) {cin >> input_name; no_heard.insert(input_name);}
    for(int i = 0; i < M; i++){
        cin >> input_name;
        if(no_heard.find(input_name) != no_heard.end()) no_heard_watched.push_back(input_name);
    }
    
    sort(no_heard_watched.begin(), no_heard_watched.end());
    
    cout << no_heard_watched.size() << '\n';
    
    for(auto name : no_heard_watched) cout << name << '\n';
    
    return 0;
}
