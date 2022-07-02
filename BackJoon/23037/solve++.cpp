#include <iostream>

using namespace std;

inline int square5(int number){
    return number * number * number * number * number;
}

int main() {
    char numbers[6];
    
    cin >> numbers;
    
    int total = 0;
    
    for(int i = 0; i < 5; i++) total += square5(numbers[i] - '0');
    
    cout << total;
    
    return 0;
}
