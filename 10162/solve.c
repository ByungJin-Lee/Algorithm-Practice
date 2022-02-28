#include <stdio.h>

int main(void){
    unsigned int T;
    scanf("%d", &T);
    
    if(T & 0x1) {
        printf("-1");
        return 0;
    }
    
    T >>= 1;
    
    if(T % 5 != 0){
        printf("-1");
        return 0;
    }
    
    T /= 5;
    
    printf("%d %d %d", T / 30, T % 30 / 6, T % 6);
    return 0;
}
