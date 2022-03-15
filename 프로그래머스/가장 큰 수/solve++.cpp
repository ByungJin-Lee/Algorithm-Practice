#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool Compare(const string &str1, const string& str2){
    return str1 + str2 > str2 + str1;
}

string solution(vector<int> numbers) {
    vector<string> unsorted;
    for(auto n : numbers){
        unsorted.push_back(to_string(n));
    }
    sort(unsorted.begin(), unsorted.end(), Compare);

    string ret = "";

    for(auto str : unsorted){
        ret += str;
    }

    return ret[0] == '0' ? "0" : ret;
}
