#include <stdio.h>
#define SWAP(t, a, b) t = a; a = b; b = t

unsigned char Ladder[1000][25];

int GetMidProcess(int K, int N, char* stored){
    int L = K - 1, I = 0, T;
    for(I = 0; I < K; I++) stored[I] = I + 'A';
    I = 0;
    while(Ladder[I][0] != 2){
        for(int j = 0; j < L; j++){
            if(Ladder[I][j]){
                SWAP(T, stored[j], stored[j+1]);
                j++;
            }
        }
        I++;
    }
    return I;
}

void GetDeltaMap(int K, int N, int S, int* delta){
    int chair[26];
    int I, T, L = K - 1;
    for(I = 0; I < K; I++) {
        delta[I] = 0;
        chair[I] = I;
    }
    I = S + 1;
    while(I < N){
        for(int j = 0; j < L; j++){
            if(Ladder[I][j]){
                delta[chair[j]]++;
                delta[chair[j+1]]--;
                SWAP(T, chair[j], chair[j+1]);
            }
        }
        I++;
    }
}

int main(void){
    int K, N, Delta[26];
    char Dest[27], Temp[26], Ret[26], Mid[27];
    scanf("%d%d%s", &K, &N, Dest);
    for(int i = 0; i < N; i++){
        scanf("%s", Temp);
        for(int j = 0, r = K - 1; j < r; j++) Ladder[i][j] = Temp[j] == '*' ? 0 : (Temp[j] == '-' ? 1 : 2);
    }
    
    GetDeltaMap(K, N, GetMidProcess(K, N, Mid), Delta);
    
    for(int i = 0; i < K; i++) Temp[i] = Dest[i + Delta[i]];
    
    for(int i = 0, r = K - 1; i < r; i++){
        if(Temp[i] == Mid[i])
            Ret[i] = '*';
        else if(Temp[i] == Mid[i+1] && Temp[i+1] == Mid[i]){
            Ret[i] = '-';
            Ret[i+1] = '*';
            i++;
        }else{
            for(int j = 0; j < r; j++) printf("x");
            return 0;
        }
    }
    
    for(int i = 0, r = K - 1; i < r; i++) printf("%c", Ret[i]);
    return 0;
}
