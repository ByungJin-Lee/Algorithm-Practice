#include <stdio.h>
#include <stdlib.h>

int* input_list;
int* sorted_list;
int* input_set;

int Compare(const void *a, const void *b)
{
    int num1 = *(int *)a, num2 = *(int *)b;

    if (num1 < num2)
        return -1;
    if (num1 > num2)
        return 1;
    return 0;
}

int RemoveDuplicatedValue(int N){
    int SetIndex = 1;
    input_set[0] = sorted_list[0];
    for(int i = 1; i < N; i++){
        if(sorted_list[i] != sorted_list[i-1])
            input_set[SetIndex++] = sorted_list[i];
    }
    return SetIndex;
}

int GetIndex(int V, int S){
    int l = 0, r = S, m = l + (r - l) / 2;
    while(1){
        if(V > input_set[m]){
            l = m + 1;
            m = l + (r - l) / 2;
        }else if(V < input_set[m]){
            r = m - 1;
            m = l + (r - l) / 2;
        }else{
            return m;
        }
    }
}

int main(void){
    int N;
    scanf("%d", &N);
    input_list = (int*)malloc(sizeof(int) * N);
    input_set = (int*)malloc(sizeof(int) * N);
    sorted_list = (int*)malloc(sizeof(int) * N);
    for(int i = 0, temp; i < N; i++) {
        scanf("%d", &temp);
        input_list[i] = sorted_list[i] = temp;
    }
    qsort(sorted_list, N, sizeof(int), Compare);
    for(int i = 0, last = RemoveDuplicatedValue(N) - 1; i < N; i++)
        printf("%d ", GetIndex(input_list[i], last));
    return 0;
}
