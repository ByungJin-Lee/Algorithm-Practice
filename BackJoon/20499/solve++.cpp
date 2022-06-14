#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

vector<string> split(string str, char sep){
    vector<string> res;
    stringstream ss(str);
    string temp;
    
    while(getline(ss, temp, sep)) res.push_back(temp);
    
    return res;
}

int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    string input;
    cin >> input;
    auto value = split(input, '/');
    int k = stoi(value[0]), d = stoi(value[1]), a = stoi(value[2]);
    
    if(k + a < d || d == 0) cout << "hasu";
    else cout << "gosu";
   
    return 0;
}
