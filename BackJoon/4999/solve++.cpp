#include <iostream>
#include <string>

using namespace std;

int main(void){
    
    string me, doctor;
    
    cin >> me >> doctor;
    
    if(me.length() >= doctor.length()) cout << "go";
    else cout << "no";
    
    return 0;
}
