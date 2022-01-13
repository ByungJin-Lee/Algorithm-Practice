#include <stdio.h>

char* predict(int N){
    if(N % 2) return "SK";
    
    return "CY";
}

int main(int argc, const char * argv[]) {
    //최선의 수는 무엇인가?
    int N;
    
    scanf("%d", &N);
    
    printf("%s", predict(N));
    return 0;
}
