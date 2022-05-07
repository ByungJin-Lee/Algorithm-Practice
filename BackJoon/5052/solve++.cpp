#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

typedef struct tagTU {
    bool joint;
    struct tagTU *branch;
} TU, *LTU;

bool sort_tel(string& lhs, string& rhs){
    return lhs.length() < rhs.length();
}

inline LTU GetNTU(){
    LTU tu = new TU[10];
    memset(tu, 0, sizeof(TU) * 10);
    return tu;
}

bool IsRightTels(vector<string>& tels){
    TU root = {0, 0};
    
    for(string& s : tels){
        LTU cur = &root;
        for(char c : s){
            int ci = c - '0';
            
            if(cur->branch == 0) cur->branch = GetNTU();
            
            if(cur->branch[ci].joint) return false;
            
            cur = &cur->branch[ci];
        }
        cur->joint = true;
    }
    return true;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    
    cin >> T;
    
    string in;
    
    for(int t = 0, tl; t < T; t++){
        cin >> tl;
        vector<string> tels;
        for(int i = 0; i < tl; i++){
            cin >> in;
            tels.push_back(in);
        }
        sort(tels.begin(), tels.end(), sort_tel);
        cout << (IsRightTels(tels) ? "YES\n" : "NO\n");
    }

    return 0;
}
