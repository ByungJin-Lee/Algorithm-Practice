#include <stdio.h>

int gcd(int N, int M){
  int tmp;
  while(M){
    tmp = N % M;
    N = M;
    M = tmp;
  }
  return N;
}

int main(void){
    int N, M, I, Ns[1001], Ms[1001], temp, Flag = 0;
    unsigned long acc = 1;

    for(scanf("%d", &N), I = N; I != 0; I--) scanf("%d", &Ns[I]);
    for(scanf("%d", &M), I = M; I != 0; I--) scanf("%d", &Ms[I]);
    
    for(int i = N; i != 0; i--){
        for(int j = M; Ns[i] != 1 && j != 0; j--){
            acc *= temp = gcd(Ns[i], Ms[j]);
            Ns[i] /= temp;
            Ms[j] /= temp;
            
            if(acc >= 1000000000){
                acc %= 1000000000;
                Flag = 1;
            }
        }
    }
    if(Flag)
        printf("%09lu", acc);
    else
        printf("%lu", acc);
    return 0;
}
