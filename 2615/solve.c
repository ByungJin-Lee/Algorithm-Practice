#include <stdio.h>

#define SIZE 19
#define END_CUT 4
#define InRange(r, c) (r >= 0 && r < SIZE && c >= 0 && c < SIZE)

int board[SIZE][SIZE];
int l_row, l_col;

short dr[8] = {0, 0, 1, -1, 1, -1, 1, -1};
short dc[8] = {1, -1, 0, 0, 1, -1, -1, 1};

int CountWithDir(int r, int c, int t, short d){
    int count = 0;
    for(int _r = r + dr[d], _c = c + dc[d];
        InRange(_r, _c);
        _r += dr[d], _c += dc[d]){
        if(board[_r][_c] == t){
            count++;
        }else{
            break;
        }
    }
    return count;
}

int CountWithLine(int r, int c){
    int t = board[r][c];
    for(short d = 0; d < 7; d += 2){
        if(CountWithDir(r, c, t, d) + CountWithDir(r, c, t, d+1) == END_CUT)
            return d;
    }
    return -1;
}

void GetLeftSide(int r, int c, short d){
    if(d == 0 || d == 2 || d == 4){
        l_row = r;
        l_col = c;
    }else{
        int count = CountWithDir(r, c, board[r][c], 6);
        l_row = r + count;
        l_col = c - count;
    }
}

int main(void){
    //Input
    for(int row = 0; row < SIZE; row++){
        for(int col = 0; col < SIZE; col++)
            scanf("%d", &board[row][col]);
    }
    
    //Run
    int d = 0;
    for(int row = 0; row < SIZE; row++){
        for(int col = 0; col < SIZE; col++){
            if(board[row][col] != 0){
                if((d = CountWithLine(row, col)) != -1){
                    GetLeftSide(row, col, d);
                    printf("%d\n%d %d", board[row][col], l_row + 1, l_col + 1);
                    return 0;
                }
            }
        }
    }
    
    printf("0");
    
    return 0;
}
