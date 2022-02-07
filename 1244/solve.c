#include <stdio.h>
#define InScope(n, e) (n > 0 && n <= e)

unsigned char Status[101];

int main(void){
    int L, S;
    scanf("%d", &L);
    for(int i = 1; i <= L; i++) scanf("%d", &Status[i]);
    scanf("%d", &S);
    for(int i = 0, g, n; i < S; i++){
        scanf("%d%d", &g, &n);
        Status[n] = !Status[n];
        if(g == 1)
            for(int j = 2, r = L / n; j <= r; Status[j * n] = !Status[j * n], j++);
        else
            for(int j = 1; InScope(n - j, L) && InScope(n + j, L) && Status[n - j] == Status[n + j]; Status[n - j] = !Status[n-j], Status[n + j] = !Status[n+j], j++);
    }
    for(int i = 1; i <= L; i++) printf("%d%c", Status[i], i % 20 == 0 ? '\n' : ' ');
    
    return 0;
}
