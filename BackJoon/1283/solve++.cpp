#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <sstream>

using namespace std;

vector<string> Split(string line, char sep){
    vector<string> res;
    stringstream ss(line);
    string temp;
    while(getline(ss, temp, sep)) res.push_back(temp);
    return res;
}

inline bool IsAlreadyIn(set<char>& keyset, char key){
    return keyset.find(key) != keyset.end();
}

int GetShortcutIndex(set<char>& keyset, string input){
    vector<string> words = Split(input, ' ');
    
    //First Alpha
    {
        int len = 0;
        for(auto word : words){
            if(word.length() != 0){
                if(!IsAlreadyIn(keyset, toupper(word[0]))) return len;
            }
            len += word.length() + 1;
        }
    }
    
    //Linear
    {
        int acc = 0;
        for(auto word : words){
            for(int i = 1, r = (int)word.length(); i < r; i++){
                if(!IsAlreadyIn(keyset, toupper(word[i])))
                    return acc + i;
            }
            acc += word.length() + 1;
        }
    }
    return -1;
}

string processStr(string line, int i){
    string content = "[";
    content += line[i];
    content += ']';
    return line.substr(0, i) + content + line.substr(i+1);
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string input;
    
    getline(cin, input);
    
    int NumOfShortcut = atoi(input.c_str());
    
    set<char> keyset;
    
    for(int i = 0; i < NumOfShortcut; i++){
        getline(cin, input);
        
        int index = GetShortcutIndex(keyset, input);
        
        if(index == -1){
            cout << input << '\n';
            continue;
        }
        
        keyset.insert(toupper(input[index]));
        
        cout << processStr(input, index) << '\n';
    }
    

    return 0;
}
