#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

typedef struct {unsigned int len; char content[51];} Word;

int Compare(const void *a, const void *b){
    Word& w1 = *(Word*)a, w2 = *(Word*)b;
    
    if(w1.len > w2.len) return 1;
    
    if(w1.len == w2.len){
        for(int i = 0; i < w1.len; i++){
            if(w1.content[i] > w2.content[i])
                return 1;
            else if(w1.content[i] < w2.content[i])
                return -1;
        }
        return 0;
    }
    return -1;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N, I, L;
    Word words[20000];
    cin >> N;
    I = N;
    while(--I >= 0){
        cin >> words[I].content;
        for(L = 0; words[I].content[L] != 0; L++) {}
        words[I].len = L;
    }
    
    qsort(words, N, sizeof(Word), Compare);
    
    cout << words[0].content << '\n';
    for(int i = 1; i < N; i++){
        if(words[i-1].len == words[i].len){
            if(memcmp(words[i-1].content, words[i].content, sizeof(char) * words[i-1].len) == 0) continue;
        }
        cout << words[i].content << '\n';
    }
    return 0;
}
