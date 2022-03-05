#include <stdio.h>
#include <string.h>

#define MAX 100
#define Dl(x) x--



int main(void){
    short plain[MAX][MAX];
    int max_x = 0, min_x = 101, max_y = 0, min_y = 101;
    int area = 0;
    
    for(int i = 0; i < MAX; i++){
        memset(plain[i], 0, sizeof(short) * MAX);
    }
    
    int l_x, l_y, r_x, r_y;
    for(int i = 0; i < 4; i++){
        scanf("%d %d %d %d", &l_x, &l_y, &r_x, &r_y);
        Dl(l_x); Dl(l_y); Dl(r_x); Dl(r_y);
        //Check Plaine Value
        for(int y = l_y; y < r_y; y++){
            for(int x = l_x; x < r_x; x++){
                plain[y][x] = 1;
            }
        }
        //Check Max and Min Range
        if(max_x < r_x)
            max_x = r_x;
        if(min_x > l_x)
            min_x = l_x;
        if(max_y < r_y)
            max_y = r_y;
        if(min_y > l_y)
            min_y = l_y;
    }
    
    //Count Blocks
    for(int y = min_y; y < max_y; y++){
        for(int x = min_x; x < max_x; x++){
            if(plain[y][x] == 1){
                area++;
            }
        }
    }
    
    //Output
    printf("%d", area);
    
    return 0;
}
