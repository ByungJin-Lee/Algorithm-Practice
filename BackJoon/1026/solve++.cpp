#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, A[50], B[50];
    
    cin >> N;
    
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < N; i++) cin >> B[i];
    
    sort(A, A+N);
    sort(B, B+N, greater<int>());
    
    int Sum = 0;
    for(int i = 0; i < N; i++) Sum += (A[i] * B[i]);
    
    cout << Sum;
    
    return 0;
}
