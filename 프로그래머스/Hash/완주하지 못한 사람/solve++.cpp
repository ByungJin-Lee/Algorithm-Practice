#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    vector<string>::iterator pItor = participant.begin()
        , cItor = completion.begin();
    
    while(true){
        if(*pItor != *cItor) return *pItor;
        pItor++; cItor++;
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    return 0;
}
