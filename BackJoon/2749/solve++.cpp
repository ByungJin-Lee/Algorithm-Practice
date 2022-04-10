#include <iostream>
#include <string>

using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    string input;
    int B, sum = 0;
    cin >> input >> B;
    
    for(int i = (int)input.length() - 1, p = 1; i >= 0; i--){
        if(isdigit(input[i]))
            sum += (input[i] - '0') * p;
        else
            sum += (input[i] - 'A' + 10) * p;
        p *= B;
    }
    
    cout << sum;
    return 0;
}
