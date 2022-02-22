#include <stdio.h>

int Values[5];

int GetMaxValue(void){
    int max = 0, temp;
    for(int i = 0; i < 3; i++){
        for(int j = i + 1; j < 4; j++){
            for(int k = j + 1; k < 5; k++){
                temp = (Values[i] + Values[j] + Values[k]) % 10;
                if(temp > max) max = temp;
            }
        }
    }
    return max;
}

int main(void)
{
    int N, Max = -1, I, T;
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < 5; j++) scanf("%d", &Values[j]);
        T = GetMaxValue();
        if(Max <= T) {Max = T; I = i;}
    }
    printf("%d", I + 1);
    return 0;
}
