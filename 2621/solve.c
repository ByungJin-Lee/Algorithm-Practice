#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tagCard {char Kind; int Num;} Card;

int Compare(const void *a, const void *b){
    int k1 = ((Card*)a)->Kind, k2 = ((Card*)b)->Kind, n1 = ((Card*)a)->Num, n2 = ((Card*)b)->Num;
    if(k1 == k2 && n1 > n2) return 1;
    
    if(k1 > k2) return 1;
    
    if(k1 == k2 && n1 == n2) return 0;
    
    return -1;
}

int GetScore(Card* deck){
    int kind = 1, chain = 0, max = deck[0].Num, Counter[10];
    memset(Counter, 0, sizeof(int) * 10);

    Counter[deck[0].Num]++;
    for(int i = 1; i < 5; i++){
        //Kind
        if(deck[i].Kind != deck[i - 1].Kind) kind++;
        //Max Number
        if(deck[i].Num > max) max = deck[i].Num;
        //Counting
        Counter[deck[i].Num]++;
    }
    
    //Chain
    for(int i = 1, t; i < 10; i++){
        if(Counter[i] > 0){
            t = 0;
            for(int j = i + 1; j < 10; j++){
                if(Counter[j] > 0) t++;
                else break;
            }
            i += t;
            if(chain < t) chain = t;
        }
    }
    
    //#1 Chain, Kind 1
    if(chain == 4 && kind == 1) return max + 900;
    //#2 Same N4
    for(int i = 1; i < 10; i++) if(Counter[i] == 4) return i + 800;
    //#3 Same N3 and N2
    for(int i = 1; i < 10; i++){
        if(Counter[i] == 3)
            for(int j = 1; j < 10; j++) if(Counter[j] == 2) return i * 10 + j + 700;
    }
    //#4 Same Kind
    if(kind == 1) return max + 600;
    //#5 Chain
    if(chain == 4) return max + 500;
    //#6 Same 3
    for(int i = 1; i < 10; i++) if(Counter[i] == 3) return i + 400;
    //#7 Same 2, Same 2
    for(int i = 1; i < 10; i++){
        if(Counter[i] == 2)
            for(int j = i + 1; j < 10; j++) if(Counter[j] == 2) return i > j ? i * 10 + j + 300 : j * 10 + i + 300;
    }
    //#8
    for(int i = 1; i < 10; i++) if(Counter[i] == 2) return i + 200;
    //Default
    return max + 100;
}

int main(void)
{
    Card cards[5];
    for(int i = 0; i < 5; i++) scanf("%c %d%*c", &cards[i].Kind, &cards[i].Num);
    qsort(cards, 5, sizeof(Card), Compare);
    printf("%d", GetScore(cards));
    return 0;
}
