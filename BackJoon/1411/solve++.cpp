#include <iostream>
#include <cstring>

using namespace std;

#define MAX_SIZE 100
#define MAX_LEN 50

bool CanTranslated(char* from, char* to){
    char tmap[27];
    bool used[27];
    memset(used, 0, sizeof(used));
    memset(tmap, 0, sizeof(tmap));
    
    int i = 0;
    while(from[i] != 0){
        int ori = from[i] - 96, dest = to[i] - 96;
        if(tmap[ori]){
            if(tmap[ori] != dest) return false;
        }else{
            if(used[dest]) return false;
            used[dest] = true;
            tmap[ori] = dest;
        }
        i++;
    }
    return true;
}


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N, NumOfPair = 0;
    
    cin >> N;
    
    char word[MAX_SIZE][MAX_LEN+1];
    
    for(int i = 0; i < N; i++) cin >> word[i];
    
    for(int i = 0, r = N - 1; i < r; i++){
        for(int j = i + 1; j < N; j++)
            NumOfPair += CanTranslated(word[i], word[j]);
    }
    
    cout << NumOfPair;
    
    return 0;
}
