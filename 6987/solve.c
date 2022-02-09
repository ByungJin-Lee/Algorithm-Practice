#include <stdio.h>
int Group[4][6][3], Match[15][2];

int Forward(int I, int g){
    if(I == 15) return 1;
    
    int L = Match[I][0], R = Match[I][1];
    
    if(Group[g][L][1] && Group[g][R][1]){
        Group[g][L][1]--; Group[g][R][1]--;
        if(Forward(I + 1, g)) return 1;
        Group[g][L][1]++; Group[g][R][1]++;
    }
    
    if(Group[g][L][0] && Group[g][R][2]){
        Group[g][L][0]--; Group[g][R][2]--;
        if(Forward(I + 1, g)) return 1;
        Group[g][L][0]++; Group[g][R][2]++;
    }
    
    if(Group[g][L][2] && Group[g][R][0]){
        Group[g][L][2]--; Group[g][R][0]--;
        if(Forward(I + 1, g)) return 1;
        Group[g][L][2]++; Group[g][R][0]++;
    }
    return 0;
}

int CheckFoul(int g){
    //Total Check
    for(int i = 0; i < 6; i++)
        if(Group[g][i][0] + Group[g][i][1] + Group[g][i][2] != 5) return 0;
    return Forward(0, g);
}

int main(void)
{
    for(int i = 0, _i = 0; i < 6; i++)
        for(int j = i + 1; j < 6; Match[_i][0] = i, Match[_i][1] = j, j++, _i++);
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 18; j++) scanf("%d", &Group[i][j / 3][j % 3]);
    for(int i = 0; i < 4; i++) {
        
        printf("%d ", CheckFoul(i));
    }
    return 0;
}
