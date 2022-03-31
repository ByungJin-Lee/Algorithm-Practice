#include <iostream>
#include <cstring>

using namespace std;

typedef struct tagPattern { tagPattern* next[2]; bool IsEnd; } Pattern;

bool IsSubmarine(char *wave){
    Pattern p[9];
    bool IsEnd = true;
    memset(p, 0, sizeof(p));
    
    Pattern* cur = &p[0];
    
    p[0].next[0] = &p[7];
    p[0].next[1] = &p[1];
    
    p[1].next[0] = &p[2];
    
    p[2].next[0] = &p[3];
    
    p[3].next[0] = &p[3];
    p[3].next[1] = &p[4];
    
    p[4].next[0] = &p[7];
    p[4].next[1] = &p[5];
    p[4].IsEnd = true;
    
    p[5].next[0] = &p[6];
    p[5].next[1] = &p[5];
    p[5].IsEnd = true;
    
    p[6].next[0] = &p[3];
    p[6].next[1] = &p[8];
    
    p[7].next[1] = &p[8];
    
    p[8].next[0] = &p[7];
    p[8].next[1] = &p[1];
    p[8].IsEnd = true;
    
    int i = 0;
    while(wave[i] != 0){
        if(cur->next[wave[i] - '0'] == 0) return false;
        cur = cur->next[wave[i] - '0'];
        IsEnd = cur->IsEnd;
        i++;
    }
    
    return IsEnd;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    char wave[151];
    
    cin >> wave;
    cout << (IsSubmarine(wave) ? "SUBMARINE" : "NOISE");
    return 0;
}
