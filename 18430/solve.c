#include <stdio.h>
#include <string.h>

#define SIZE 5
#define InRange(r, c, N, M) (r >= 0 && r < N && c >= 0 && c < M)
int strength[SIZE][SIZE];
int visited[SIZE][SIZE];
int MN, MM, MV = 0;

int type[4][2][2] = {
    {
        {-1, 0}, //Row, Column
        {0, 1},
    },
    {
        {-1, 0},
        {0, -1},
    },
    {
        {1, 0},
        {0, 1},
    },
    {
        {1, 0},
        {0, -1},
    }
};

#define DrawType(r, c, t) visited[r][c] = visited[r + type[t][0][0]][c + type[t][0][1]] = visited[r + type[t][1][0]][c + type[t][1][1]] = 1

#define UnDrawType(r, c, t) visited[r][c] = visited[r + type[t][0][0]][c + type[t][0][1]] = visited[r + type[t][1][0]][c + type[t][1][1]] = 0

#define CanType(r, c, t) (!visited[r][c] && InRange(r + type[t][0][0], c + type[t][0][1], MN, MM) && InRange(r + type[t][1][0], c + type[t][1][1], MN, MM) && !visited[r + type[t][0][0]][c + type[t][0][1]] && !visited[r + type[t][1][0]][c + type[t][1][1]])

#define GetStrengthWithType(r, c, t) strength[r + type[t][0][0]][c + type[t][0][1]] + strength[r + type[t][1][0]][c + type[t][1][1]] + 2 * strength[r][c]

void Recursive(int r, int c, int sum){
    if(c == MM){
        c = 0;
        r++;
    }
    if(r == MN){
        if(MV < sum)
            MV = sum;
        return;
    }
    
    if(CanType(r, c, 0)){
        DrawType(r, c, 0);
        Recursive(r, c + 1, sum + GetStrengthWithType(r, c, 0));
        UnDrawType(r, c, 0);
    }
    if(CanType(r, c, 1)){
        DrawType(r, c, 1);
        Recursive(r, c + 1, sum + GetStrengthWithType(r, c, 1));
        UnDrawType(r, c, 1);
    }
    if(CanType(r, c, 2)){
        DrawType(r, c, 2);
        Recursive(r, c + 1, sum + GetStrengthWithType(r, c, 2));
        UnDrawType(r, c, 2);
    }
    if(CanType(r, c, 3)){
        DrawType(r, c, 3);
        Recursive(r, c + 1, sum + GetStrengthWithType(r, c, 3));
        UnDrawType(r, c, 3);
    }
    Recursive(r, c+1, sum);
}

int main(void){
    for(int i = 0; i < SIZE; i++)
        memset(visited[i], 0, sizeof(int) * SIZE);
    //Input
    scanf("%d%d", &MN, &MM);
    for(int r = 0; r < MN; r++){
        for(int c = 0; c < MM; c++)
            scanf("%d", &strength[r][c]);
    }
    
    //Print
    Recursive(0, 0, 0);
    printf("%d", MV);
    return 0;
}
