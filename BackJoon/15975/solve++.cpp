#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//N개의 점이 주어짐, N개의 색상이 있음,
//N개의 점의 좌표는 모두다 다름
//점 p, q를 선택하여 직선을 연결하는데, q는 p와 색상이 같고 p에서 가장 가까운 점이다.
//q가 다수인 경우, 아무거나 선택한다

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    long long sum = 0;
    
    vector<int> colors[100001];
    
    cin >> N;
    
    for(int i = 0, x, y; i < N; i++){
        cin >> x >> y;
        colors[y].push_back(x);
    }
    
    for(int i = 1; i <= N; i++) sort(colors[i].begin(), colors[i].end());
    
    for (int i = 1; i <= N; i++) {
        if(colors[i].size() < 2) continue;
        
        vector<int>& vec = colors[i];
        int size = (int)vec.size();
        for(int j = 1, r = size - 1; j < r; j++)
            sum += min(vec[j] - vec[j-1], vec[j+1] - vec[j]);
        sum += (vec[1] - vec[0] + vec[size-1] - vec[size-2]);
    }
    cout << sum;
    
    return 0;
}
