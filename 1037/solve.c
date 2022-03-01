#include <stdio.h>

int main(void){
    int N, T, min, max;
    scanf("%d", &N);
    scanf("%d", &T);
    max = min = T;
    while(--N != 0){
        scanf("%d", &T);
        if(max < T) max = T;
        if(min > T) min = T;
    }
    printf("%d", min * max);
    return 0;
}
