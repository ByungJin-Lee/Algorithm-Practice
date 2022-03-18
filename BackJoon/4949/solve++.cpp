#include <stack>
#include <string>
#include <iostream>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string sentence;
    
    while(true){
        bool isSuc = true;
        getline(cin, sentence);
        
        if(sentence[0] == '.') break;
        
        stack<char> bracket;
        
        for(char c : sentence){
            if(c == '[' || c == '('){
                bracket.push(c);
            }
            else if(c == ']' || c == ')'){
                if(bracket.empty()) {
                    isSuc = false;
                    break;
                }
                if(c == ']'){
                    if(bracket.top() != '[') {
                        isSuc = false;
                        break;
                    }
                    bracket.pop();
                }else{
                    if(bracket.top() != '(') {
                        isSuc = false;
                        break;
                    }
                    bracket.pop();
                }
            }
        }
        
        cout << (isSuc && bracket.empty() ? "yes\n" : "no\n");
    }
    
    return 0;
}
