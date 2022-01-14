#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 101

int compare(const void *a, const void *b)
{
    int num1 = *(int *)a;
    int num2 = *(int *)b;

    if (num1 < num2)
        return -1;
    
    if (num1 > num2)
        return 1;
    
    return 0;
}

int main(void){
    int N, L = 0;
    int number_pairs[MAX_SIZE];
    int number_index[MAX_SIZE];
    int order_index[MAX_SIZE];
    int chk[MAX_SIZE];
    //입력을 받는다.
    scanf("%d", &N);
    
    for(int i = 1; i <= N; i++){
        scanf("%d", &number_pairs[i]);
    }
    
    for(int i = 1; i <= N; i++){
        if(number_pairs[i] < i) continue;
        memset(chk, 1, sizeof(int) * MAX_SIZE);
        
        int next = number_pairs[i];
        int order_len = 1;
        
        order_index[0] = i;
        chk[i] = 0;
        
        while(next > i && chk[next]){
            chk[next] = 0;
            order_index[order_len++] = next;
            next = number_pairs[next];
        }
        
        if(i == next){
            for(int j = 0; j < order_len; j++){
                number_index[L++] = order_index[j];
            }
        }
    }
    
    //Sort
    qsort(number_index, L, sizeof(int), compare);
    
    printf("%d", L);
    for(int i = 0; i < L; i++){
        printf("\n%d", number_index[i]);
    }
    
    return 0;
}
