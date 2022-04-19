#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

inline bool IsPrime(unsigned int num){
    for(int i = 2; i * i <= num; i++)
        if(num % i == 0) return false;
    return true;
}

inline unsigned int Image(unsigned int number){
    unsigned int value = 0;
    while(number > 0){
        value = value * 10 + number % 10;
        number /= 10;
    }
    return value;
}

vector<unsigned int> ExtractPalindrome(){
    vector<unsigned int> palis;
    
    palis.push_back(5);
    palis.push_back(7);
    
    int upper = 10, back;
    for(int i = 1; i < 1000; i++){
        if(i >= upper) upper *= 10;
        back = Image(i);
        //ABA
        for(int m = 0, d_upper = upper * 10; m < 10; m++)
            palis.push_back(i * d_upper + m * upper + back);
        //AA
        palis.push_back(i * upper + back);
    }
    for(int i = 1000; i < 10000; i++)
        palis.push_back(i * 10000 + Image(i));
    sort(palis.begin(), palis.end());
    return palis;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    unsigned int a, b;
    vector<unsigned int> palis = ExtractPalindrome();
    
    cin >> a >> b;
    
    for(auto p : palis){
        if(p < a) continue;
        if(p > b) break;
        
        if(IsPrime(p)) cout << p << '\n';
    }
    cout << -1;
    
    return 0;
}
