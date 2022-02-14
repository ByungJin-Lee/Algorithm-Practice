#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int N, H, T, D;
    char *Commands, *Numbers, Temp[5];
    Commands = (char*)malloc(sizeof(char) * 100001);
    Numbers = (char*)malloc(sizeof(char) * 100000);
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        D = 1; H = 0;
        
        scanf("%s", Commands);
        scanf("%d", &T);
        
        while(getchar() != '[') {}
        for(int j = 0; j < T; j++){
            scanf("%[0-9]", Temp);
            Numbers[j] = atoi(Temp);
            getchar();
        }
        
        for(int j = 0; Commands[j]; j++){
            if(Commands[j] == 'R'){
                D = !D;
            }else{
                if(T - H > 0){
                    if(D) H++;
                    else T--;
                }else{
                    D = 2;
                    break;
                }
            }
        }
        
        while(getchar() != '\n') {}
        
        if(D == 2) {
            printf("error\n");
            continue;
        }
        
        printf("[");
        if(T - H){
            if(D){
                for(int j = H, e = T - 1; j < e; j++) printf("%d,", Numbers[j]);
                printf("%d", Numbers[T-1]);
            }else{
                for(int j = T - 1; j > H; j--) printf("%d,", Numbers[j]);
                printf("%d", Numbers[H]);
            }
        }
        printf("]\n");
    }
    return 0;
}
