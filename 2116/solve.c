#include <stdio.h>

unsigned char Dices[10000][7];

int StackDice(int i, int a, int end){
    if(i == end) return 0;
    
    int score = 0, back = Dices[i][a];
    
    if(a != 6 && back != 6) score = 6;
    
    else if((a == 6 && back != 5) || (a != 5 && back == 6)) score = 5;
    
    else score = 4;
    
    return StackDice(i+1, back, end) + score;
}

int main(void)
{
    int N, MAX = 0;
    scanf("%d", &N);
    for(int i = 0, l1_f, l1_b, l2_f, l2_b, l3_f, l3_b; i < N; i++){
        scanf("%d%d%d%d%d%d", &l1_f, &l2_f, &l3_f, &l2_b, &l3_b, &l1_b);
        Dices[i][l1_f] = l1_b;
        Dices[i][l1_b] = l1_f;
        Dices[i][l2_f] = l2_b;
        Dices[i][l2_b] = l2_f;
        Dices[i][l3_f] = l3_b;
        Dices[i][l3_b] = l3_f;
    }
    
    for(int i = 0, t; i < 6; i++){
        t = StackDice(0, i + 1, N);
        if(MAX < t) MAX = t;
    }
    printf("%d", MAX);
    
    return 0;
}
