#include <iostream>
#include <cstdlib>
#include <algorithm>
#define NONE 1000

using namespace std;

inline int Evaluate(int arr[], int n){
    int score = 0;
    for(int i = 0, r = n - 1; i < r; i++) score += abs(arr[i] - arr[i+1]);
    return score;
}

int Forward(int i, int n, int arr[8], int extra[8]){
    if(i == n) return Evaluate(arr, n);
        
    int score = 0;
    
    for(int j = 0; j < n; j++){
        if(extra[j] != NONE){
            arr[i] = extra[j];
            extra[j] = NONE;
            score = max(score, Forward(i+1, n, arr, extra));
            extra[j] = arr[i];
        }
    }
    return score;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, arr[8], extra[8];
    
    cin >> N;
    
    
    for(int i = 0; i < N; i++){
        cin >> arr[i];
        extra[i] = arr[i];
    }
    
    cout << Forward(0, N, arr, extra);
    
    return 0;
}
