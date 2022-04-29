#include <iostream>
#include <cstring>

using namespace std;

typedef struct {
    int count, digits;
    int n[10];
} DesendingNum;

inline void Increase(DesendingNum& num){
    num.count++;
    num.n[9]++;
    for (int i = 9, r = 10 - num.digits; i > r; i--){
        if (num.n[i] >= num.n[i - 1]){
            num.n[i - 1]++;
            num.n[i] = 9 - i;
        }
        else break;
    }
    if (num.n[10 - num.digits] > 9){
        num.digits++;
        for (int i = 9, r = 9 - num.digits; i > r; i--){
            num.n[i] = 9 - i;
        }
    }
}

int main(void){
    DesendingNum num = { 0, 1, {0,} };
    memset(num.n, 0, sizeof(num.n));
    int n;
    cin >> n;

    if (n > 1022){
        cout << -1;
        return 0;
    }
    while (num.count < n)
        Increase(num);
    for (int i = 10 - num.digits; i < 10; i++)
        cout << num.n[i];
}
