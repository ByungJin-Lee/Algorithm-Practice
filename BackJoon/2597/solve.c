#include <stdio.h>

typedef struct tagPair{double p1, p2;} Pair;

int main(void)
{
    double L, M;
    Pair pairs[3];
    scanf("%lf", &L);
    for(int i = 0; i < 3; i++) scanf("%lf%lf", &pairs[i].p1, &pairs[i].p2);
    for(int i = 0; i < 3; i++){
        M = (pairs[i].p1 + pairs[i].p2) / 2;
        if(pairs[i].p1 != pairs[i].p2){
            L = L / 2 > M ? L - M : M;
            for(int j = i + 1; j < 3; j++){
                pairs[j].p1 = pairs[j].p1 < M ? M - pairs[j].p1 : pairs[j].p1 - M;
                pairs[j].p2 = pairs[j].p2 < M ? M - pairs[j].p2 : pairs[j].p2 - M;
            }
        }
    }
    printf("%.1lf", L);
    return 0;
}
