#include <stdio.h>
#define MAX 50

typedef struct tagDNA{ unsigned char IsSame; int head[50], tail[50]; } DNA;
DNA Ori, DNAs[100];

int CompareDNA(DNA a, DNA b, int L){
    for(int i = 0, j, r; i < L; i++){
        if(a.head[0] == b.head[i]){
            for(j = r = 1; j < L; j++){
                if(a.head[j] == b.head[(i + j) % L]) continue;
                r = 0; break;
            }
            if(r) return 1;
        }
        if(a.head[0] == b.tail[i]){
            for(j = r = 1; j < L; j++){
                if(a.head[j] == b.tail[(i + j) % L]) continue;
                r = 0; break;
            }
            if(r) return 1;
        }
    }
    return 0;
}

int main(void){
    int DNA_SIZE, DNA_LENGTH, count = 0;
    scanf("%d", &DNA_LENGTH);
    for(int i = 0; i < DNA_LENGTH; i++) scanf("%d", &Ori.head[i]);
    scanf("%d", &DNA_SIZE);
    for(int i = 0, L = DNA_LENGTH - 1, V; i < DNA_SIZE; i++){
        for(int j = 0; j < DNA_LENGTH; j++){
            scanf("%d", &V);
            DNAs[i].head[j] = V;
            DNAs[i].tail[L - j] = V < 3 ? V + 2 : V - 2;
        }
        count += DNAs[i].IsSame = CompareDNA(Ori, DNAs[i], DNA_LENGTH);
    }
    printf("%d\n", count);
    for(int i = 0; i < DNA_SIZE; i++){
        if(DNAs[i].IsSame){
            for(int j = 0; j < DNA_LENGTH; j++) printf("%d ", DNAs[i].head[j]);
            printf("\n");
        }
    }
}
