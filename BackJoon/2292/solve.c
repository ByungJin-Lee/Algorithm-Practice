#include <stdio.h>

int main(void){
    int N;
    scanf("%d", &N);
    for(int l = 0, r = 1, i = 1; ; l = r, r += (6*i), i++){
        if(l < N && N <= r){
            printf("%d", i);
            break;
        }
    }
    return 0;
}
