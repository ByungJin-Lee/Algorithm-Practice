#include <stdio.h>
#include <string.h>
#define InScope(v, n) (v > 0 && v <= N)

int N;

void DrawQueenArea(int x, int y, unsigned short *Board){
    for(int d = y - 1; d != 0; d--){
        if(InScope(y-d, N)){
            Board[y-d] |= 1 << x;
            if(InScope(x-d, N)) Board[y-d] |= 1 << (x-d);
            if(InScope(x+d, N)) Board[y-d] |= 1 << (x+d);
        }
    }
}

int Forward(int x, int y, int Q, unsigned short* Board){
    if(x == 0) {x = N; y--;}
    
    if(Q == 0) return 1;
    
    if(y == 0 || y < Q) return 0;
    
    if((Board[y] & 1 << x) == 0){
        unsigned short nBoard[15];
        memcpy(nBoard, Board, sizeof(unsigned short) * 15);
        DrawQueenArea(x, y, nBoard);
        return Forward(N, y-1, Q - 1, nBoard) + Forward(x - 1, y, Q, Board);
    }
    return Forward(x - 1, y, Q, Board);
}

int main(void)
{
    unsigned short Board[15];
    memset(Board, 0, sizeof(unsigned short) * 15);
    scanf("%d", &N);
    printf("%d", Forward(N, N, N, Board));
    return 0;
}
