#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tagDocument { unsigned char identify, priority; struct tagDocument* next; } Docment, *LPDoc;

int Prioritys[10];

//Tail->next = head return new Tail
LPDoc AppendToTail(LPDoc tail, int priority){
    LPDoc nTail = (LPDoc)malloc(sizeof(Docment));
    nTail->next = tail->next;
    nTail->identify = tail->identify + 1;
    tail->next = nTail;
    nTail->priority = priority;
    return nTail;
}

LPDoc GetTail(int priority){
    LPDoc nTail = (LPDoc)malloc(sizeof(Docment));
    nTail->next = nTail;
    nTail->priority = priority;
    nTail->identify = 0;
    return nTail;
}
//Return Prev Unit
LPDoc GetMaxDoc(LPDoc head, int N, int Limit){
    int max = 0;
    LPDoc max_doc = 0, prev = head, item = head->next;
    while(N != 0){
        if(max < item->priority){
            max = item->priority;
            max_doc = prev;
            if(max == Limit) break;
        }
        prev = prev->next;
        item = prev->next;
        N--;
    }
    return max_doc;
}

LPDoc GetPrintedSeq(LPDoc tail, int N){
    int limit = 9, not_used = N;
    LPDoc used_side = 0, not_used_side = tail, prev_max, max;
    
    while(not_used != 0){
        //Set Limit
        while(limit != 0){
            if(Prioritys[limit]){
                Prioritys[limit]--;
                break;
            }
            limit--;
        }
        //Get Max Doc
        prev_max = GetMaxDoc(not_used_side, not_used, limit);
        max = prev_max->next;
        //Front To Back;
        prev_max->next = max->next;
        not_used_side = prev_max;
        if(used_side == 0){
            used_side = max;
            used_side->next = used_side;
        }else{
            max->next = used_side->next;
            used_side->next = max;
            used_side = max;
        }
        not_used--;
    }
    
    return used_side;
}

int Search(LPDoc doc, int N, int V){
    int I = 0;
    while(I < N){
        if(V == doc->identify) return I + 1;
        doc = doc->next;
        I++;
    }
    return -1;
}

int main(void)
{
    int T, N, Target, Pri;
    LPDoc tail;
    scanf("%d", &T);
    for(int i = T; i != 0; i--){
        memset(Prioritys, 0, sizeof(int)*10);
        scanf("%d%d", &N, &Target);
        //Create First Tail
        scanf("%d", &Pri);
        tail = GetTail(Pri);
        Prioritys[Pri] = 1;
        for(int j = 1; j < N; j++) {
            scanf("%d", &Pri);
            Prioritys[Pri]++;
            tail = AppendToTail(tail, Pri);
        }
        tail = GetPrintedSeq(tail, N);
        printf("%d\n", Search(tail->next, N, Target));
    }
    return 0;
}
