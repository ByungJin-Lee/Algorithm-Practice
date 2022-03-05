#include <stdio.h>
#include <string.h>
#define InScope(r, c, er, ec) r >= 0 && r < er && c >= 0 && c < ec
unsigned char Plate[100][100], uvisted[100][100];

int RemoveOutterLayor(int R, int C){
    for(int i = 0; i < R; i++) memset(uvisted[i], 1, sizeof(unsigned char) * C);

    int count = 0, s, e, l;
    s = l = 0;
    e = 1;
    
    short que[10000][2];
    que[0][0] = que[0][1] = 0;
    
    while(e - s){
        for(int i = s, r, c; i < e; i++){
            r = que[i][0]; c = que[i][1];
            //Up
            if(InScope(r - 1, c, R, C) && uvisted[r-1][c]){
                uvisted[r-1][c] = 0;
                if(Plate[r - 1][c] == 0){
                    que[e + l][0] = r - 1;
                    que[e + l][1] = c;
                    l++;
                }else if(Plate[r-1][c] == 1){
                    Plate[r-1][c] = 0;
                    count++;
                }
            }
            //Right
            if(InScope(r, c + 1, R, C) && uvisted[r][c + 1]){
                uvisted[r][c + 1] = 0;
                if(Plate[r][c + 1] == 0){
                    que[e + l][0] = r;
                    que[e + l][1] = c + 1;
                    l++;
                }else if(Plate[r][c + 1] == 1){
                    Plate[r][c + 1] = 0;
                    count++;
                }
            }
            //Down
            if(InScope(r + 1, c, R, C) && uvisted[r+1][c]){
                uvisted[r+1][c] = 0;
                if(Plate[r + 1][c] == 0){
                    que[e + l][0] = r + 1;
                    que[e + l][1] = c;
                    l++;
                }else if(Plate[r+1][c] == 1){
                    Plate[r+1][c] = 0;
                    count++;
                }
            }
            //Left
            if(InScope(r, c - 1, R, C) && uvisted[r][c-1]){
                uvisted[r][c-1] = 0;
                if(Plate[r][c-1] == 0){
                    que[e + l][0] = r;
                    que[e + l][1] = c-1;
                    l++;
                }else if(Plate[r][c-1] == 1){
                    Plate[r][c-1] = 0;
                    count++;
                }
            }
        }
        s = e;
        e += l;
        l = 0;
    }
    return count++;
}

int main(void)
{
    int R, C, Rm = 0, Rc = 0, CC = 0;
    scanf("%d%d", &R, &C);
    for(int i = 0; i < R; i++)
        for(int j = 0; j < C; CC += Plate[i][j], j++) scanf("%d", &Plate[i][j]);
    while(CC > 0){
        Rm = RemoveOutterLayor(R, C);
        CC -= Rm;
        Rc++;
    }
    printf("%d\n%d", Rc, Rm);
    return 0;
}
