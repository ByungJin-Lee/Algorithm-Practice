#include <stdio.h>
#include <stdlib.h>

#define IsSame(v1, v2) v1.gold == v2.gold && v1.silver == v2.silver && v1.bronze == v2.bronze

struct Reward {unsigned int identify, gold, silver, bronze; };

struct Reward Rewards[1000];

int Compare(const void *a, const void *b){
    struct Reward r1 = *(struct Reward*)a, r2 = *(struct Reward*)b;
    
    if(r1.gold > r2.gold) return -1;
    
    else if(r1.gold == r2.gold){
        if(r1.silver > r2.silver) return -1;
        
        if(r1.silver == r2.silver){
            if(r1.bronze > r2.bronze) return -1;
            else if(r1.bronze == r2.bronze) return 0;
        }
    }
    return 1;
}

int main(void){
    unsigned int N, K, CUR = 1;
    struct Reward reward;
    scanf("%d %d", &N, &K);
    for(int i = N - 1; i >= 0; i--) {
        scanf("%d %d %d %d",
              &reward.identify,
              &reward.gold,
              &reward.silver,
              &reward.bronze);
        Rewards[i] = reward;
    }
    qsort(Rewards, N, sizeof(struct Reward), Compare);
    
    if(Rewards[0].identify != K){
        for(int i = 1, prev = 1; i < N; i++){
            //Set Priority
            if(IsSame(Rewards[i], Rewards[i-1])) CUR = prev;
            else CUR = prev = i + 1;

            if(Rewards[i].identify == K) break;
        }
    }
    printf("%d", CUR);
    return 0;
}
