#include <iostream>
#include <string>

using namespace std;

int main(void){
    string input;
    
    while(getline(cin, input)){
        cout << input << '\n';
    }
    return 0;
}
