#include <iostream>
#include <string>

using namespace std;

int check(char chr){
    switch (chr) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
            return 1;
        default:
            return 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string chr;
    
    while(true){
        int count = 0, len = 0;
        getline(cin, chr);
        while(chr[len] != 0){
            count += check(chr[len]);
            len++;
        }
        if(len == 1 && chr[0] == '#'){
            break;
        }else{
            cout << count << '\n';
        }
        
    }
    
    
    
    return 0;
}
