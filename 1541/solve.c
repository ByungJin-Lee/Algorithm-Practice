#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char Expression[51], value[6];
    int Nested = 0, L = 0, R = 0, T;
    scanf("%s", Expression);
    for(int i = 0, vi = 0; Expression[i]; i++){
        if(Expression[i] == '+' || Expression[i] == '-'){
            T = atoi(value);
            vi = 0;
            if(Nested){
                R += T;
                if(Expression[i] == '-'){
                    L -= R;
                    R = 0;
                }
            }else{
                L += T;
                if(Expression[i] == '-') Nested = 1;
            }
        }else{
            value[vi++] = Expression[i];
            value[vi] = 0;
        }
    }
    R += atoi(value);
    if(Nested) L -= R;
    else L += R;
    printf("%d", L);
    return 0;
}
