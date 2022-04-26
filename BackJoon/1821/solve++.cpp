#include <iostream>
#include <string>

using namespace std;

int LEN, ANSWER;

inline bool evaluate(int *values){
    int acc[10];
    for(int i = 0; i < LEN; i++) acc[i] = values[i];
    
    for(int n = LEN - 1; n > 0; n--)
        for(int i = 0; i < n; i++) acc[i] = acc[i] + acc[i+1];
    return acc[0] == ANSWER;
}

bool Forward(int i, bool *keys, int *values){
    if(i == LEN) return evaluate(values);
    
    for(int k = 0; k < LEN; k++){
        if(keys[k]){
            values[i] = k+1;
            keys[k] = false;
            if(Forward(i+1, keys, values))
                return true;
            keys[k] = true;
        }
    }
    return false;
}


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int values[10];
    bool keys[10];
    
    for(int i = 0; i < 10; i++) keys[i] = true;
    
    cin >> LEN >> ANSWER;
    
    Forward(0, keys, values);
    
    for(int i = 0; i < LEN; i++)
        cout << values[i] << ' ';
    
    return 0;
}
