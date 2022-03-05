#include <stdio.h>
#define abs(V) (V < 0 ? -V : V)
int Spec[100000];

int GetFloorIndex(const int V, const int N){
    int L = N - 1, S = 0, M = L / 2;
    
    while(L - S >= 0){
        if(Spec[M] == V) return M;
        
        if(Spec[M] > V) L = M - 1;
        else S = M + 1;
        
        M = (S + L) / 2;
    }
    return M;
}

int main(void)
{
    int N, C1, C2, TL, TR, COM = 2000000000;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) scanf("%d", &Spec[i]);
    for(int i = 0, tv = 2000000000; i < N; tv = 2000000000, i++){
        TL = GetFloorIndex(-Spec[i], N);
        TR = TL + 1;
        //Check Left Or Right
        if(TL != i){
            tv = abs((Spec[TL] + Spec[i]));
            if(tv < COM){
                C1 = i; C2 = TL;
                COM = tv;
            }
        }
        if(TR != i && TR < N){
            tv = abs((Spec[TR] + Spec[i]));
            if(tv < COM){
                C1 = i; C2 = TR;
                COM = tv;
            }
        }
    }
    if(C1 < C2)
        printf("%d %d", Spec[C1], Spec[C2]);
    else
        printf("%d %d", Spec[C2], Spec[C1]);
    return 0;
}
