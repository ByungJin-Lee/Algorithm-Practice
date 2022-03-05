#include <stdio.h>
#include <string.h>
#define MAX 50
#define InRange(r, c, mr, mc) (r >= 0 && r < mr && c >= 0 && c < mc)

unsigned char Farm[MAX][MAX];
typedef struct tagPOS {short r; short c;} Pos;
Pos Que[MAX * MAX];

int GetMinEarthworm(int row, int col, int k){
    int count = 0;
    //Reset Farm
    for(int i = 0; i < row; i++) memset(Farm[i], 0, sizeof(unsigned char) * col);
    //Build Farm
    for(int c = 0, _r, _c; c < k; c++){
            scanf("%d%d", &_c, &_r);
            Farm[_r][_c] = 1;
    }
    //BFS
    int q_start, q_end, q_delta;
    for(int ir = 0; ir < row; ir++){
        for(int ic = 0; ic < col; ic++){
            //Condition
            if(!Farm[ir][ic]) continue;
            //Que
            Farm[ir][ic] = 0;
            count++;
            Que[0].r = ir; Que[0].c = ic;
            q_start = q_delta = 0;
            q_end = 1;
            
            while(q_end - q_start > 0){
                for(int q_i = q_start, r, c; q_i < q_end; q_i++){
                    r = Que[q_i].r;
                    c = Que[q_i].c;
                    //Up
                    if(InRange(r - 1, c, row, col) && Farm[r-1][c]){
                        Farm[r-1][c] = 0;
                        Que[q_end + q_delta].r = r - 1;
                        Que[q_end + q_delta].c = c;
                        q_delta++;
                    }
                    //Right
                    if(InRange(r, c + 1, row, col) && Farm[r][c+1]){
                        Farm[r][c + 1] = 0;
                        Que[q_end + q_delta].r = r;
                        Que[q_end + q_delta].c = c + 1;
                        q_delta++;
                    }
                    //Down
                    if(InRange(r+1, c, row, col) && Farm[r+1][c]){
                        Farm[r+1][c] = 0;
                        Que[q_end + q_delta].r = r + 1;
                        Que[q_end + q_delta].c = c;
                        q_delta++;
                    }
                    //Left
                    if(InRange(r, c - 1, row, col) && Farm[r][c - 1]){
                        Farm[r][c - 1] = 0;
                        Que[q_end + q_delta].r = r;
                        Que[q_end + q_delta].c = c - 1;
                        q_delta++;
                    }
                }
                q_start = q_end;
                q_end += q_delta;
                q_delta = 0;
            }
        }
    }
    return count;
}

int main(void){
    int T, M, N, K;
    scanf("%d", &T);
    for(int i = 0; i < T; i++){
        scanf("%d%d%d", &M, &N, &K);
        printf("%d\n", GetMinEarthworm(N, M, K));
    }
    
    return 0;
}
