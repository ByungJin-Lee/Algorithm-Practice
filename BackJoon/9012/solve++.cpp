#include <iostream>
#include <string>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    string str;
    
    cin >> N;
    
    while(N-- != 0){
        cin >> str;
        int evaluate = 0;
        
        for(char c : str){
            if(c == '(') evaluate++;
            else if(--evaluate < 0) break;
        }
        cout << (evaluate == 0 ? "YES\n" : "NO\n");
    }
    
    return 0;
}
