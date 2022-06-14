//solve 10808
#include <iostream>
#include <cstring>

using namespace std;

int main(void){
    char word[101];
    int counter[26];
    memset(counter, 0, sizeof(counter));
    
    cin >> word;
    
    int i = 0;
    while(word[i] != 0){
        counter[word[i] - 'a']++;
        i++;
    }
    
    for(i = 0; i < 26; i++) cout << counter[i] << ' ';
    
    return 0;
}
