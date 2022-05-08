#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#define D0 0b0111111
#define D1 0b0001010
#define D2 0b1011101
#define D3 0b1001111
#define D4 0b1101010
#define D5 0b1100111
#define D6 0b1110111
#define D7 0b0001011
#define D8 0b1111111
#define D9 0b1101011

using namespace std;

inline int TranslateCode(int bcode){
    switch (bcode) {
        case D0: return 0;
        case D1: return 1;
        case D2: return 2;
        case D3: return 3;
        case D4: return 4;
        case D5: return 5;
        case D6: return 6;
        case D7: return 7;
        case D8: return 8;
        case D9: return 9;
    }
    return -1;
}

string n_template[10] = {"063", "010", "093", "079", "106", "103", "119", "011", "127", "107"};

string TranslateNumber(int number){
    string num = "";
    
    while(number > 0){
        num = n_template[number%10] + num;
        number /= 10;
    }
    return num;
}

int ReadDigit(string num){
    int i = 0, r = (int)num.length(), v = 0;
    while(i < r){
        v = v * 10 + TranslateCode(stoi(num.substr(i, 3)));
        i += 3;
    }
    return v;
}

vector<string> Split(string& in, char deli){
    stringstream ss(in);
    vector<string> splited;
    string temp;
    while(getline(ss, temp, deli)) splited.push_back(temp);
    return splited;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string expression;
    
    while(true){
        cin >> expression;
        
        if(expression == "BYE") break;
        
        cout << expression;
        
        expression.erase(expression.length() - 1);
        
        int sum = 0;
        for(auto num : Split(expression, '+')){
            sum += ReadDigit(num);
        }
        
        cout << TranslateNumber(sum) << '\n';
    }
    
    return 0;
}
