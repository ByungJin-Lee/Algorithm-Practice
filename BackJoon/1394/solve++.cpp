#include <iostream>
#include <unordered_map>

#define MO 900528
#define MAX_SET_SIZE 100
#define MAX_PW_SIZE 1000000

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long res = 0;
    
    char pwSet[MAX_SET_SIZE + 1], pwTar[MAX_PW_SIZE + 1];
    
    cin >> pwSet >> pwTar;
    
    unordered_map<char, int> translator;
    int i = 0, dup = 0;
    while(pwSet[i] != 0){
        if(translator.find(pwSet[i]) == translator.end())
            translator.insert({ pwSet[i], i-dup+1 });
        else dup++;
        i++;
    }
    
    int depth = 0, K = (int)translator.size();
    
    while(pwTar[depth] != '\0') ++depth;
    
    long long acc = 1;
    
    while(--depth >= 0){
        res = (res + acc * translator[pwTar[depth]]) % MO;
        acc = (acc * K) % MO;
    }
    cout << res;
    return 0;
}
