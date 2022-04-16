#include <iostream>
#include <vector>

using namespace std;

int top;

class BigBinaryNumber{
private:
    int digits[50];
    int capacity = 50;
    int length = 1;
public:
    BigBinaryNumber(){
        for(int i = 0; i < capacity; i++)
            digits[i] = 0;
        digits[capacity-1] = 2;
    }
    void Multi(){
        int calced, upper = 0;
        for(int i = capacity - 1, c = 0; c < length; c++, i--){
            calced = digits[i] * 2 + upper;
            digits[i] = (calced % 10);
            upper = calced / 10;
        }
        if(upper){
            length++;
            digits[capacity - length] = upper;
        }
    }
    BigBinaryNumber& operator--(){
        int calced, upper = -1;
        for(int i = capacity - 1, c = 0; c < length; c++, i--){
            calced = digits[i] + upper;
            if(calced < 0){
                digits[i] = 9;
                upper = -1;
            }
            else{
                digits[i] = calced;
                upper = 0;
            }
            if(upper == 0) break;
        }
        return *this;
    }
    void Pow(int count){
        for(int i = 1; i < count; i++) Multi();
    }
    void Print(){
        for(int i = capacity - length; i < 50; i++)
            cout << digits[i];
    }
};

void move(int l, int s, int d){
    if (l > top) return;
    int dest = 6 - s - d;
    move(l + 1, s, dest);
    cout << s << ' ' << d << '\n';
    move(l + 1, dest, d);
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> top;
    BigBinaryNumber num = BigBinaryNumber();
    num.Pow(top);
    --num;
    num.Print();
    
    if(top <= 20) {
        cout << '\n';
        move(1, 1, 3);
    }

    return 0;
}
