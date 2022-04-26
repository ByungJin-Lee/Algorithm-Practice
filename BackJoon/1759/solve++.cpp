#include <iostream>
#include <algorithm>

using namespace std;

int LEN, NUM_OF_KEY;
char keys[15];

inline void evaluate(char *values){
    int NumOfVowel = 0;
    for(int i = 0; i < LEN; i++)
        switch (values[i]) {
            case 'a': case 'e': case 'i': case 'o': case 'u':
                NumOfVowel++;
                break;
        }
    if(NumOfVowel > 0 && LEN - NumOfVowel > 1) cout << values << '\n';
}

void Forward(int i, int last, char *values){
    if(i == LEN) return evaluate(values);
    
    for(int k = last, r = NUM_OF_KEY - LEN + i; k <= r; k++){
        values[i] = keys[k];
        Forward(i+1, k+1, values);
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    char values[16];
    for(int i = 0; i < 16; i++) values[i] = 0;
    
    cin >> LEN >> NUM_OF_KEY;
    
    for(int i = 0; i < NUM_OF_KEY; i++) cin >> keys[i];
    
    sort(keys, keys + NUM_OF_KEY);
    
    Forward(0, 0, values);
    
    return 0;
}
