#include <stdio.h>

unsigned int Rule[8][6] = {
    {0,0,0,0,0,0},
    {0,0,1,1,1,1},
    {0,1,0,0,1,1},
    {0,1,1,1,0,0},
    {1,0,0,1,1,0},
    {1,0,1,0,0,1},
    {1,1,0,1,0,1},
    {1,1,1,0,1,0}
};
unsigned int Latter[10 * 6];

int GetLessErrorChr(int S){
    int min = 6, min_i = -1;
    
    for(int i = 0, start = S * 6, temp; i < 8; i++){
        temp = 0;
        for(int j = 0; j < 6; j++)
            if(Latter[start + j] != Rule[i][j]) temp++;
        if(temp < min){
            min = temp;
            min_i = i;
        }
    }
    
    return min > 1 ? -1 : min_i;
}

void ReadLatters(int N){
    char Temp[10];
    for(int i = 0; i < N; i++){
        if((Temp[i] = GetLessErrorChr(i)) == -1){
            printf("%d", i + 1);
            return;
        }
    }
    
    for(int i = 0; i < N; i++) printf("%c", Temp[i] + 'A');
}


int main(void)
{
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < 6; j++) scanf("%1d", &Latter[i * 6 + j]);
    ReadLatters(N);
    return 0;
}
