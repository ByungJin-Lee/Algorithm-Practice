#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string input;
    
    while(true){
        getline(cin, input);
        
        if(input == "END") break;
        
        reverse(input.begin(), input.end());
        
        cout << input << '\n';
    }
    
    return 0;
}
