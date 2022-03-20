#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define NONE 0

using namespace std;

char signs[10];

vector<string> vs;

inline void Evaluate(int n, char s[10]){
    for(int i = 0, r = n - 1; i < r; i++){
        if(signs[i] == '<'){
            if(s[i] >= s[i+1]) return;
        }else{
            if(s[i] <= s[i+1]) return;
        }
    }
    string v = "";
    for(int i = 0; i < n; i++) v += s[i];
    vs.push_back(v);
}

void Forward(int i, int n, char s[10], char extra[10]){
    if(i == n) return Evaluate(n, s);
    
    for(int j = 0; j < 10; j++){
        if(extra[j] != NONE){
            s[i] = extra[j];
            extra[j] = NONE;
            Forward(i+1, n, s, extra);
            extra[j] = s[i];
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    char arr[10], extra[10];
    
    cin >> N;
    
    for(int i = 0; i < N; i++) cin >> signs[i];
    
    for(int i = 0; i < 10; i++) extra[i] = i + '0';
    
    Forward(0, N+1, arr, extra);
    
    cout << vs.back() << '\n' << vs.front();
    
    return 0;
}
