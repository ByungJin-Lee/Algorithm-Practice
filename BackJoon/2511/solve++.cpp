#include <iostream>

#define WinPoint 3
#define DrawPoint 1

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    unsigned int A[10], B[10], I = 0, pointA = 0, pointB = 0;
    char lastWinner = 'D';
    while(I < 10) cin >> A[I++];
    I = 0;
    while(I < 10) cin >> B[I++];
    
    //Compare
    for(int i = 0; i < 10; i++){
        if(A[i] == B[i]){
            pointA += DrawPoint;
            pointB += DrawPoint;
        }else if(A[i] > B[i]){
            pointA += WinPoint;
            lastWinner = 'A';
        }else{
            pointB += WinPoint;
            lastWinner = 'B';
        }
    }
    
    cout << pointA << ' ' << pointB << '\n' << (pointA == pointB ? lastWinner : (pointA > pointB ? 'A' : 'B'));
    return 0;
}
