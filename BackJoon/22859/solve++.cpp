#include <iostream>
#include <queue>
#include <string>

using namespace std;

inline string ReadTag(string& html, int& idx){
    int start = idx;
    while(html[idx++] != '>') {}
    return html.substr(start, idx - start);
}

inline string ReadContent(string& html, int& idx){
    int start = idx;
    while(html[++idx] != '<') {}
    return html.substr(start, idx - start);
}

inline void Trim(string &content){
    content.erase(0, content.find_first_not_of(' '));
    content.erase(content.find_last_not_of(' ') + 1);
}

inline string Parse(string& content){
    Trim(content);
    
    int start, end, len = (int)content.length();
    start = end = 0;
    
    string res = "";
    
    while(start < len){
        start = (int)content.find_first_not_of(' ', end);
        end = (int)content.find(' ', start) + 1;
        
        if(end == 0)
            return res + content.substr(start);
        else
            res += content.substr(start, end - start);
        start = end;
    }
    
    return res;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    queue<string> tags;
    string raw, content;
    getline(cin, raw);
    
    int cur = 0, len = (int)raw.length();
    
    while(cur < len){
        if(raw[cur] == '<'){
            string v = ReadTag(raw, cur);
            
            if(v.find("div ", 1, 4) == 1)
                cout << "title : " + v.substr(12, v.length() - 14) << '\n';
            else if(v == "<p>")
                content = "";
            else if(v == "</p>")
                cout << Parse(content) << '\n';
        }else{
            content.append(ReadContent(raw, cur));
        }
    }
    
    return 0;
}
