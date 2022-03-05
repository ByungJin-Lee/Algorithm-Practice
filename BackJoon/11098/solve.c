#include <stdio.h>
#include <string.h>

#define MAX 100
#define NAME_SIZE 20 + 1

int main(void){
    int N;
    int T;
    int money, highest;
    
    char people[MAX][NAME_SIZE];
    char temp_name[NAME_SIZE];
    
    scanf("%d", &N);
    
    for(int N_c = 0; N_c < N; N_c++){
        scanf("%d", &T);
        money = 0; highest = 0;
        for(int T_c = 0; T_c < T; T_c++){
            scanf("%d %s", &money, temp_name);
            if(money > highest){
                highest = money;
                strcpy(people[N_c], temp_name);
            }
        }
    }
    
    for(int i = 0; i < N; i++){
        printf("%s\n", people[i]);
    }
    return 0;
}
