#include <iostream>
#include <stack>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    unsigned int res[500000];
    stack<pair<unsigned int, unsigned int>> towers;
    
    cin >> N;
    
    for(unsigned int i = 0, hg, p; i < N; i++){
        cin >> hg;
        p = 0;
        while(!towers.empty()){
            if(towers.top().second > hg){
                p = towers.top().first;
                break;
            }
            towers.pop();
        }
        res[i] = p;
        towers.push(make_pair(i+1, hg));
    }
    for(int i = 0; i < N; i++)
        cout << res[i] << ' ';
    return 0;
}
