#include <iostream>
#include <string>
#include <cmath>

using namespace std;

string NUM[10] = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };

inline bool IsOperater(char chr){
    return chr == '+' || chr == '-' || chr == '/' || chr == 'x' || chr == '=';
}

int ReadStrangeNumber(string& expression, int& i){
    int number = 0;
    do{
        string target = expression.substr(i, 5);
        for(int k = 0; k < 10; k++){
            if(target.find(NUM[k]) == 0){
                number = number * 10 + k;
                i += NUM[k].length();
                break;
            }
            if(k == 9) return -1;
        }
    }while(!IsOperater(expression[i]));
    return number;
}

string TranslateStrange(long long value){
    string res = value >= 0 ? "" : "-";
    for(char& c : to_string(value)) res += NUM[c - '0'];
    return res;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    string expression, res_expression = "";
    cin >> expression;
    int len = (int)expression.length() - 1, i = 0, j, rhs_num;
    long long lhs = (long long)ReadStrangeNumber(expression, i);
    bool IsValid = lhs > -1;
    res_expression += to_string(lhs);
    
    while(IsValid && i < len){
        if(IsOperater(expression[i])){
            if(expression[i] == '=') {
                IsValid = false;
                break;
            }
            j = i++;
            res_expression.push_back(expression[j]);
            rhs_num = ReadStrangeNumber(expression, i);
            if(rhs_num > -1){
                res_expression += to_string(rhs_num);
                switch (expression[j]) {
                    case '+': lhs += rhs_num; break;
                    case '-': lhs -= rhs_num; break;
                    case 'x': lhs *= rhs_num; break;
                    case '/': lhs /= rhs_num; break;
                }
            }else{
                IsValid = false;
            }
        }
    }
    if(IsValid) cout << res_expression <<"=\n" << TranslateStrange(lhs);
    else cout << "Madness!";
    return 0;
}
