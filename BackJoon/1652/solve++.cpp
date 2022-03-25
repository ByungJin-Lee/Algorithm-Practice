#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    
    bool spot[100][100];
    
    cin >> N;
    char v[101];
    for(int i = 0; i < N; i++){
        cin >> v;
        for(int j = 0; j < N; j++) spot[i][j] = v[j] == '.';
    }
    
    int vertical = 0, horizontal = 0;
    bool IsLayDown = false;
    
    //horizontal
    for(int r = 0; r < N; r++){
        IsLayDown = false;
        for(int c = 0; c < N-1; c++){
            if(spot[r][c]){
                if(!IsLayDown && spot[r][c+1]){
                    IsLayDown = true;
                    horizontal++;
                }
            }else if(IsLayDown) IsLayDown = false;
        }
    }
    //vertical
    for(int c = 0; c < N; c++){
        IsLayDown = false;
        for(int r = 0; r < N-1; r++){
            if(spot[r][c]){
                if(!IsLayDown && spot[r+1][c]){
                    IsLayDown = true;
                    vertical++;
                }
            }else if(IsLayDown) IsLayDown = false;
        }
    }
    
    cout << horizontal << ' ' << vertical;
    
    return 0;
}
