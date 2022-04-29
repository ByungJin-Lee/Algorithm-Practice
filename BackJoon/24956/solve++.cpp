#include <iostream>
#include <string>
#include <vector>

#define MO 1000000007

using namespace std;

inline int powT(int c){
    if (c < 30) return 1 << c;

    long long val = 1;

    while (c > 30){
        val = (val << 30) % MO;
        c -= 30;
    }

    return (val << c) % MO;
}

inline int Case(const int NumOfW, const int NumOfE){
    return (NumOfW * ((long long)powT(NumOfE) - NumOfE - 1)) % MO;
}

int CountCase(vector<pair<int, int>>& h, const int TW, const int TE){
    long long cases = 0;
    for (auto item : h){
        cases += Case(item.first, TE - item.second);
        cases %= MO;
    }
    return (int)cases;
}

int main(void){
    int len, NumOfW = 0, NumOfE = 0;
    char in[200001];

    cin >> len >> in;

    vector<pair<int, int>> vec;

    for (int i = 0; i < len; i++){
        switch (in[i]){
        case 'W': NumOfW++;
            break;
        case 'E': NumOfE++;
            break;
        case 'H': vec.push_back(make_pair(NumOfW, NumOfE));
            break;
        }
    }

    cout << CountCase(vec, NumOfW, NumOfE);
}
