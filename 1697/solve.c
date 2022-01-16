#include <stdio.h>
#include <string.h>

#define MAX 100001

typedef unsigned char BYTE;

int main(void){
    //Init
    int time = -1, N, K, I, V;
    
    scanf("%d %d", &N, &K);
    
    if(N >= K){
        time = N - K;
    }else{
        BYTE flags[MAX];
        int que[MAX];
        int que_start, que_temp, que_last;
        int loop_count = 0;
        memset(flags, 0, sizeof(BYTE) * MAX);
        
        //Que Setting
        que_start = 0; que_temp = 0; que_last = 1;
        que[0] = K;
        //Check
        flags[K] = 1;
        //Loop(Not Empty Que)
        while(que_last - que_start > 0){
            loop_count++;
            //Travel
            for(I = que_start; I < que_last; I++){
                V = que[I];
                //Check
                if(V == N){
                    que_temp = 0;
                    break;
                }
                //Minus and Plus
                if(flags[V-1] == 0){
                    flags[V-1] = 1;
                    que[que_last + que_temp] = V - 1;
                    que_temp++;
                }
                if(flags[V+1] == 0){
                    flags[V+1] = 1;
                    que[que_last + que_temp] = V + 1;
                    que_temp++;
                }
                //Divide
                if(V % 2 == 0 && flags[V/2] == 0){
                    flags[V/2] = 1;
                    que[que_last + que_temp] = V / 2;
                    que_temp++;
                }
            }
            //Que Range
            que_start = que_last;
            que_last += que_temp;
            que_temp = 0;
        }
        time = loop_count - 1;
    }
    
    printf("%d", time);
    return 0;
}
