#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

typedef struct tagNumMap {
    bool IsEnd;
    struct tagNumMap* content[10];
} NumMap, *LNumMap;

inline LNumMap GetNewNumMap(bool isEnd){
    LNumMap map = new NumMap;
    memset(map, 0, sizeof(NumMap));
    map->IsEnd = isEnd;
    return map;
}

bool solution(vector<string> phone_book) {
    vector<string>::iterator itor = phone_book.begin(),
            end = phone_book.end();
        
    NumMap table, *cur;
    memset(&table, 0, sizeof(NumMap));
    int I, R, idx;
    
    while(itor != end){
        cur = &table;
        string& item = *itor;
        
        I = 0; R = (int)item.length() - 1;
        while(I < R){
            idx = item[I] - '0';
            if(cur->content[idx]){
                if(cur->content[idx]->IsEnd) return false;
            }else
                cur->content[idx] = GetNewNumMap(false);
            cur = cur->content[idx];
            I++;
        }
        if(cur->content[(idx = item[I] - '0')]) return false;
        else cur->content[idx] = GetNewNumMap(true);
        itor++;
    }
    return true;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    return 0;
}
