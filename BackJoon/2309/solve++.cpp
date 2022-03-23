#include <iostream>
#include <algorithm>
#include <stack>
#define NONE 101

using namespace std;

stack<int> numpu;

bool Forward(int arr[9], int i, int e, int sum){
    if(e == 0) return sum == 100;
    
    if(sum >= 100) return false;
    
    for(int j = 0, temp; j < 9; j++){
        if(arr[j] == NONE) continue;
        temp = arr[j];
        arr[j] = NONE;
        if(Forward(arr, i+1, e-1, sum+temp)) {
            numpu.push(temp);
            return true;
        }
        arr[j] = temp;
    }
    return false;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int height[9];
    
    for(int i = 0; i < 9; i++) cin >> height[i];
    
    sort(height, height+9);
    
    Forward(height, 0, 7, 0);
    
    for(int i = 0; i < 7; i++){
        cout << numpu.top() << '\n';
        numpu.pop();
    }
    
    return 0;
}
