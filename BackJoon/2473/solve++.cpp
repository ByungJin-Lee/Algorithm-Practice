#include <iostream>
#include <algorithm>

using namespace std;

int NumOfFeature, features[5000], seq[3];

inline unsigned int ABS(long long value){
    return (unsigned int)(value >= 0 ? value : -value);
}

inline bool FindCase(int start, unsigned int& candidate){
    long long origin = features[start-1];
    int end = NumOfFeature - 1;
    
    while(start < end){
        long long tsum = origin + features[start] + features[end];
        
        if(ABS(tsum) < candidate){
            seq[0] = (int)origin; seq[1] = features[start]; seq[2] = features[end];
            candidate = ABS(tsum);
            if(candidate == 0)
                return true;
        }
        
        if(tsum > 0) end--;
        else start++;
    }
    return false;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> NumOfFeature;
    
    for(int i = 0; i < NumOfFeature; i++)
        cin >> features[i];
    
    sort(features, features + NumOfFeature);
    
    unsigned int candidate = 4000000000;
    
    for(int i = 0; i < NumOfFeature - 2; i++)
        if(FindCase(i+1, candidate)) break;
    
    cout << seq[0] << ' ' << seq[1] << ' ' << seq[2];

    return 0;
}
