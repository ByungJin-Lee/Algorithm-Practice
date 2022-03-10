#include <iostream>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int ExtraApple = 0, NumOfStud, NumOfApple, NumOfSchool;
    cin >> NumOfSchool;
    while(NumOfSchool-- != 0){
        cin >> NumOfStud >>  NumOfApple;
        ExtraApple += (NumOfApple % NumOfStud);
    }
    cout << ExtraApple;
    
    return 0;
}
