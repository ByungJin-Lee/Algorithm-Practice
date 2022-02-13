#include <stdio.h>
#include <stdlib.h>

int ACC_Guest[50001], DP[50001][3];

int Step, End;

int BuildDP(void){
    DP[0][0] = DP[0][1] = DP[0][2] = 0;
    int next = Step, back = 1 - Step, V, T = ACC_Guest[End];
    
    for(int i = 0; i < End; back++, next++, i++){
        V = End > next ? ACC_Guest[next] - ACC_Guest[i] : T - ACC_Guest[i];
        DP[i+1][0] = V > DP[i][0] ? V : DP[i][0];
        if(back < 0) continue;
        DP[i+1][1] = V + DP[back][0] > DP[i][1] ? V + DP[back][0] : DP[i][1];
        DP[i+1][2] = V + DP[back][1] > DP[i][2] ? V + DP[back][1] : DP[i][2];
    }
    return DP[End][2];
}

int main(void)
{
    ACC_Guest[0] = 0;
    scanf("%d", &End);
    for(int i = 1; i <= End; ACC_Guest[i] += ACC_Guest[i-1], i++) scanf("%d", &ACC_Guest[i]);
    scanf("%d", &Step);
    printf("%d", BuildDP());
    return 0;
}
