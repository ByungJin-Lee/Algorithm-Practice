#include <stdio.h>
#include <stdlib.h>

typedef struct tagMeeting{ unsigned int start, end; } Meeting;

Meeting *Meetings;

int Compare(const void *a, const void *b){
    int n1 = ((Meeting*)a)->end, n2 = ((Meeting*)b)->end, s1 = ((Meeting*)a)->start, s2 = ((Meeting*)b)->start;
    if(n1 > n2) return 1;
    
    if(n1 == n2 && s1 > s2) return 1;
    
    if(n1 == n2 && s1 == s2) return 0;
    
    return -1;
}

int main(void)
{
    int N, C = 0, S = 0;
    scanf("%d", &N);
    Meetings = (Meeting*)malloc(sizeof(Meeting) * N);
    for(int i = 0; i < N; i++) scanf("%u%u", &Meetings[i].start, &Meetings[i].end);
    qsort(Meetings, N, sizeof(Meeting), Compare);
    for(int i = 0; i < N; i++){
        if(Meetings[i].start >= S){
            S = Meetings[i].end;
            C++;
        }
    }
    printf("%d", C);
    return 0;
}
