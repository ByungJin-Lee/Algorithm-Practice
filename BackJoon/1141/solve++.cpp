#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool sort_len(string& lhs, string& rhs){
    return lhs.length() < rhs.length();
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int len, sublen = 0;
    string items[50];
    
    cin >> len;
    
    for(int i = 0; i < len; i++) cin >> items[i];
    
    sort(items, items + len, sort_len);
    
    for(int i = 0; i < len; i++){
        bool IsNotPrefix = true;
        string& val = items[i];
        for(int j = i + 1; IsNotPrefix && j < len; j++)
            if(items[j].find(val) == 0) IsNotPrefix = false;
        if(IsNotPrefix) sublen++;
    }
    
    cout << sublen;

    return 0;
}
