#include <iostream>

using namespace std;

int main(void){
    int metrix[100][100];
    
    int R, C, V;
    
    cin >> R >> C;
    
    for(int r = 0; r < R; r++){
        for(int c = 0; c < C; c++){
            cin >> metrix[r][c];
        }
    }
    
    for(int r = 0; r < R; r++){
        for(int c = 0; c < C; c++){
            cin >> V;
            metrix[r][c] += V;
        }
    }
    
    for(int r = 0; r < R; r++){
        for(int c = 0; c < C; c++){
            cout << metrix[r][c] << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}
