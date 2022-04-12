#include <iostream>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M, count = 0;
    char input[1000001];
    
    cin >> N >> M >> input;
    
    /*
     P(N)이 있을 때, P(X)의 갯수는?
    
     P(2) -> P(2) : 1
     
     P(3) -> P(2) : 2
    
     P(4) -> P(2) : 3
     
     => N - X + 1 개
    */
    
    for(int i = 0, r = M - 2; i < r; i++){
        if(input[i] != 'I' || input[i+1] != 'O' || input[i+2] != 'I') continue;
        
        int l = 1;
        for(i += 2; i < r; i += 2){
            if(input[i] == 'I' && input[i+1] == 'O' && input[i+2] == 'I') l++;
            else break;
        }
        if(l >= N) count += (l - N + 1);
    }
    cout << count;
    
    return 0;
}
