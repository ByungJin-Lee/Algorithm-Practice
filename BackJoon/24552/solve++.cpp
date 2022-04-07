#include <iostream>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int tt[100000], N = 1, count = 0, last = -1;
    char input[100001];
    
    cin >> input;
    
    tt[0] = input[0] == '(' ? 1 : -1;
    
    while(input[N] != 0){
        tt[N] = tt[N-1] + (input[N] == '(' ? 1 : -1);
        if(tt[N] == 0) last = N;
        N++;
    }
    
    if(tt[N-1] == 1){
        //Remove '('
        for(int i = last + 1; i < N; i++)
            if(input[i] == '(') count++;
    }else{
        //Remove ')'
        for(int i = 0; i < N; i++){
            if(input[i] == ')') count++;
            if(tt[i] == -1) break;
        }
    }
    
    cout << count;
    
    return 0;
}
