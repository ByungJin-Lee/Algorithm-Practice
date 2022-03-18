#include <string>
#include <cmath>
#include <iostream>

using namespace std;

//최빈값, 산술 평균, 중앙값, 범위

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, counter[8001], acc[8001], mn = 8000, mx = 0, p = 0;
    memset(counter, 0, sizeof(counter));
    
    cin >> N;
    
    for(int i = 0, v; i < N; i++){
        cin >> v;
        v += 4000;
        if(mn > v) mn = v;
        if(mx < v) mx = v;
        counter[v]++;
    }
    
    for(int i = mn; i <= mx; i++){
        if(counter[i] == 0) continue;
        acc[i] = p += counter[i];
    }
    
    int sorted[500000], sum = 0, prev_f, prev_v, cur_f, cur_v;
    prev_v = cur_v = mx;
    prev_f = cur_f = counter[mx];
    
    for(int i = mx; i >= mn; i--){
        if(counter[i] == 0) continue;
        
        sum += ((i - 4000) * counter[i]);
        
        if(counter[i] >= cur_f){
            prev_f = cur_f;
            prev_v = cur_v;
            cur_f = counter[i];
            cur_v = i;
        }
        
        fill(sorted + acc[i] - counter[i], sorted + acc[i] , i);
    }

    cout << (int)round(sum / (double)N) << '\n'
        << sorted[N/2] - 4000 << '\n'
        << (cur_f != prev_f ? cur_v : prev_v) - 4000 << '\n'
        << mx - mn;
    
    
    
    
    return 0;
}
