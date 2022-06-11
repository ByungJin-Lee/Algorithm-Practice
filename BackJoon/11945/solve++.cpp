#include <iostream>
#include <stack>

using namespace std;

int main(void){
    int R, C;
    char v;
    
    cin >> R >> C;
    
    for(int r = 0; r < R; r++){
        stack<int> intStack;
        for(int c = 0;  c < C; c++){
            cin >> v;
            intStack.push(v == '0' ? 0 : 1);
        }
        while(!intStack.empty()) {
            cout << intStack.top();
            intStack.pop();
        }
        cout << '\n';
    }
    
    
    return 0;
}
