#include <iostream>

using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    char input[100001];
    
    int sum = 0, prev = 0, i = 0;
    
    cin >> input;
    
    while(input[i] != 0){
        if(input[i] == '('){
            prev++;
        }else{
            prev--;
            if(input[i-1] == '(') sum += prev;
            else sum += 1;
        }
        i++;
    }
    
    cout << sum;
    
    return 0;
}
