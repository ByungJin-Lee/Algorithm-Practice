#include <stdio.h>

int Combination[31][31];

void BuildCombination(const int Max){
    Combination[0][0] = Combination[0][1] = Combination[1][1] = Combination[1][0] = 1;
    for(int n = 2; n <= Max; n++){
        Combination[n][0] = 1;
        for(int k = n; k > 0; k--)
            Combination[n][k] = Combination[n-1][k] + Combination[n-1][k-1];
    }
}

int main(void)
{
    int R, C, K, SUM, E;
    scanf("%d%d%d", &R, &C, &K);
    BuildCombination(R+C);
    if(K == 0){
        printf("%d", Combination[R + C - 2][R - 1]);
    }else{
        SUM = Combination[E = (K-1)/C + (K-1) % C][(K-1) %C];
        SUM *= Combination[R + C - E - 2][C - (K-1)%C - 1];
        printf("%d", SUM);
    }
    return 0;
}
