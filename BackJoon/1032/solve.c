#include <stdio.h>

#define R_SIZE 50
#define STR_SIZE 51

int main(void){
    int N, CHECK;
    char str[R_SIZE][STR_SIZE];
    char pattern[STR_SIZE];
    
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%s", str[i]);
    }
    
    for(int i = 0; str[0][i] != 0; i++){
        CHECK = 0;
        for(int j = 1; j < N; j++){
            if(str[j-1][i] != str[j][i]){
                CHECK = 1;
                break;
            }
        }
        pattern[i] = CHECK ? '?' : str[0][i];
        pattern[i+1] = 0;
        
    }
    
    printf("%s", pattern);
    return 0;
}
