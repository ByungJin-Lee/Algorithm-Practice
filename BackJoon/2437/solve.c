#include <stdio.h>
#include <stdlib.h>

int Chu[1000];

int Compare(const void *a, const void *b){
    int n1 = *(int*)a, n2 = *(int*)b;
    if(n1 > n2) return 1;
    if(n2 > n1) return -1;
    return 0;
}

int main(void)
{
    int N, Tar = 1;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) scanf("%d", &Chu[i]);
    qsort(Chu, N, sizeof(int), Compare);
    for(int i = 0; i < N; i++){
        if(Tar < Chu[i]) break;
        Tar += Chu[i];
    }
    printf("%d", Tar);
    return 0;
}
