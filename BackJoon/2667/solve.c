#include <stdio.h>
#include <stdlib.h>

#define MAX 25

#define MAX_QUE 625

int size;

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

char vertex_list[25][26];

int compare(const void *a, const void *b)
{
    int num1 = *(int *)a;
    int num2 = *(int *)b;

    if (num1 < num2)
        return -1;
    
    if (num1 > num2)
        return 1;
    
    return 0;
}

//탐색을 한 다음, 방문한 노드의 수를 반환함
int BFS(int row, int col){
    //Start Point
    int visited_count = 1;
    
    int queue_r[MAX_QUE], queue_c[MAX_QUE];
    int queue_start = 0;
    int queue_last = 1;
    int queue_temp = 0;
    queue_r[0] = row; queue_c[0] = col;
    
    while(queue_last - queue_start > 0){
        for(int i = queue_start; i < queue_last; i++){
            for(int d = 0; d < 4; d++){
                int temp_r = queue_r[i] + dr[d];
                int temp_c = queue_c[i] + dc[d];
                
                if(temp_c < 0 || temp_c >= size || temp_r < 0 || temp_r >= size) continue;
                
                if(vertex_list[temp_r][temp_c] == '1'){
                    //Uncheck
                    visited_count++;
                    vertex_list[temp_r][temp_c] = '0';
                    
                    queue_r[queue_last + queue_temp] = temp_r;
                    queue_c[queue_last + queue_temp] = temp_c;
                    queue_temp++;
                }
            }
        }
        queue_start = queue_last;
        queue_last += queue_temp;
        queue_temp = 0;
    }
    return visited_count;
}

int main(int argc, const char * argv[]) {
    
    scanf("%d", &size);
    
    for(int i = 0; i < size; i++)
        scanf("%s", vertex_list[i]);
    
    int group_count = 0;
    int group_vertex_list[625];
    
    for(int r = 0; r < size; r++){
        for(int c = 0; c < size; c++){
            if(vertex_list[r][c] == '1'){
                vertex_list[r][c] = '0';
                group_vertex_list[group_count] = BFS(r,c);
                group_count++;
            }
        }
    }
    
    qsort(group_vertex_list, group_count, sizeof(int), compare);
    
    printf("%d", group_count);
    
    for(int i = 0; i< group_count; i++){
        printf("\n%d", group_vertex_list[i]);
    }
    
    return 0;
}
