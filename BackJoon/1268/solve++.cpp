#include <iostream>
#include <unordered_set>

using namespace std;

typedef struct {unsigned int NumberOfStudent, StudentIndex[1000];} SchoolClass;

unsigned int student[1000][5];
SchoolClass classes[5][10];

int GetAdjFriendNumber(int studendId, int N){
    unordered_set<unsigned int> uset;
    SchoolClass target;
    for(int i = 0; i < 5; i++){
        target = classes[i][student[studendId][i]];
        for(int j = 0, r = target.NumberOfStudent; j < r; j++){
            uset.insert(target.StudentIndex[j]);
        }
    }
    
    return (int)uset.size();
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N, F, S, T, FO, FI;
    unsigned int (*stud);
    cin >> N;
    for(int i = 0; i < N; i++){
        stud = student[i];
        cin >> F >> S >> T >> FO >> FI;
        stud[0] = F;
        stud[1] = S;
        stud[2] = T;
        stud[3] = FO;
        stud[4] = FI;
        
        classes[0][F].StudentIndex[classes[0][F].NumberOfStudent++] =
        classes[1][S].StudentIndex[classes[1][S].NumberOfStudent++] =
        classes[2][T].StudentIndex[classes[2][T].NumberOfStudent++] =
        classes[3][FO].StudentIndex[classes[3][FO].NumberOfStudent++] =
        classes[4][FI].StudentIndex[classes[4][FI].NumberOfStudent++] = i;
    }
    //Check
    int Max = GetAdjFriendNumber(0, N), MaxI = 0;
    for(int i = 1, t; i < N; i++){
        t = GetAdjFriendNumber(i, N);
        if(Max < t){
            Max = t;
            MaxI = i;
        }
    }
    
    cout << MaxI + 1;
    return 0;
}
