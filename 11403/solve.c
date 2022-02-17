#include <stdio.h>

unsigned char Ori[100][100];

void FW(int N){
    for(int m = 0; m < N; m++){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(Ori[i][j] || (Ori[i][m] && Ori[m][j])) Ori[i][j] = 1;
            }
        }
    }
}

int main(void)
{
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++) scanf("%d", &Ori[i][j]);
    FW(N);
    for(int i = 0; i<N;i++){
        for(int j = 0; j < N; j++){
            printf("%d ", Ori[i][j]);
        }
        printf("\n");
    }
    return 0;
}
