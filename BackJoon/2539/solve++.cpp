#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int CountRequiredPaper(vector<int>& errors, const int len){
    int required = 0, lenCol = 0;
    for(int& e : errors){
        if(e <= lenCol) continue;
        lenCol = e + len - 1;
        required++;
    }
    return required;
}

int main(void){
    
    int paperRow, paperCol, NumOfUsedPaper, NumOfError, maxRow = 0;
    
    cin >> paperRow >> paperCol >> NumOfUsedPaper >> NumOfError;
    
    vector<int> errors;
    int _i = NumOfError, _r, _c;
    
    while(_i-- != 0) {
        cin >> _r >> _c;
        if(_r > maxRow) maxRow = _r;
        errors.push_back(_c);
    }
    
    sort(errors.begin(), errors.end());
    
    int l = maxRow, r = max(paperCol, paperRow), m = 0;
    
    while(l < r){
        m = (l + r) / 2;
        if(CountRequiredPaper(errors, m) <= NumOfUsedPaper) r = m;
        else l = m + 1;
    }
    cout << l;
    
    return 0;
}
