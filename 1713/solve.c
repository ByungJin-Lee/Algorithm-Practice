#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 101

typedef struct tagFrame{
    int voted_count;
    int time;
    int owner;
} Frame;

int VotedSet[MAX];
Frame Frames[20];
int F_SIZE, F_Cur = 0;

int Compare(const void *a, const void *b)
{
    int num1 = ((Frame*)a)->owner;
    int num2 = ((Frame*)b)->owner;

    if (num1 < num2)
        return -1;
    
    if (num1 > num2)
        return 1;
    
    return 0;
}

int GetMinIndex(void){
    int min = 0;
    for(int i = 1; i < F_Cur; i++){
        if(Frames[i].voted_count < Frames[min].voted_count)
            min = i;
        else if(Frames[i].voted_count == Frames[min].voted_count && Frames[i].time < Frames[min].time)
            min = i;
    }
    return min;
}

void Vote(int v, int t){
    if(VotedSet[v] != -1){
        Frames[VotedSet[v]].voted_count++;
    }else{
        if(F_Cur != F_SIZE){
            VotedSet[v] = F_Cur;
            Frames[F_Cur].voted_count = 1;
            Frames[F_Cur].time = t;
            Frames[F_Cur].owner = v;
            F_Cur++;
        }else{
            int victim = GetMinIndex();
            VotedSet[Frames[victim].owner] = -1;
            VotedSet[v] = victim;
            Frames[victim].owner = v;
            Frames[victim].time = t;
            Frames[victim].voted_count = 1;
        }
    }
}

int main(void){
    memset(VotedSet, -1, sizeof(int) * MAX);
    int vote_size;
    scanf("%d%d", &F_SIZE, &vote_size);
    for(int c = 0, temp; c < vote_size; c++){
        scanf("%d", &temp);
        Vote(temp, c);
    }
    qsort(Frames, F_Cur, sizeof(Frame), Compare);
    for(int i = 0; i < F_Cur; i++){
        printf("%d ", Frames[i].owner);
    }
    
    return 0;
}
