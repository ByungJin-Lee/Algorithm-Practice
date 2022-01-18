#include <stdio.h>

int value[4];

int GetWatchValue(int V){
    int temp = V;
    for(int i = 0; i < 3; i++){
        V = V % 1000 * 10 + V / 1000;
        if(temp > V) temp = V;
    }
    return temp;
}

int CountWatchValueLessThan(int W){
    int count = 0;
    for(int v = 1111; v < W; v++){
        if(GetWatchValue(v) == v){
            count++;
        }
    }
    return count;
}

int main(void){
    for(int i = 0; i < 4; i++)
        scanf("%d", &value[i]);
    printf("%d", 1 + CountWatchValueLessThan(GetWatchValue(value[0] * 1000 + value[1] * 100 + value[2] * 10 + value[3])));
}
