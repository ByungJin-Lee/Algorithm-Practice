#include <iostream>
#include <string>

using namespace std;

struct ScoreStandard {
    string name, score;
};

int main(void){
    struct ScoreStandard ss[13];
    
    ss[0] = {"A+", "4.3"};
    ss[1] = {"A0", "4.0"};
    ss[2] = {"A-", "3.7"};
    ss[3] = {"B+", "3.3"};
    ss[4] = {"B0", "3.0"};
    ss[5] = {"B-", "2.7"};
    ss[6] = {"C+", "2.3"};
    ss[7] = {"C0", "2.0"};
    ss[8] = {"C-", "1.7"};
    ss[9] = {"D+", "1.3"};
    ss[10] = {"D0", "1.0"};
    ss[11] = {"D-", "0.7"};
    ss[12] = {"F", "0.0"};
    
    string input;
    
    cin >> input;
    
    for(int i = 0; i < 13; i++){
        if(input == ss[i].name){
            cout << ss[i].score;
            break;
        }
    }
    
    return 0;
}
