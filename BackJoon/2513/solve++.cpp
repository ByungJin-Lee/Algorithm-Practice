#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct {int pos, numOfStud;} Spot, *LSpot;

int Compare(const void *a, const void *b){
    LSpot v1 = (LSpot)a, v2 = (LSpot)b;
    if(v1->pos > v2->pos) return 1;
    if(v1->pos < v2->pos) return -1;
    return 0;
}

int BinarySearchPos(LSpot arr, int N, int V){
    int l = 0, r = N, m;
    while(l <= r){
        m = (l+r)/2;
        if(arr[m].pos == V) return m;
        if(arr[m].pos > V) r = m - 1;
        else l = m + 1;
    }
    return -1;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    Spot spots[30001];
    
    int NumOfApart, BusCapacity, SchoolPos, Movement = 0, I = 0;
    
    cin >> NumOfApart >> BusCapacity >> SchoolPos;
    
    while(I < NumOfApart) {
        cin >> spots[I].pos >> spots[I].numOfStud;
        ++I;
    }
    spots[I].pos = SchoolPos;
    
    qsort(spots, NumOfApart+1, sizeof(Spot), Compare);
    
    int SchoolIdx = BinarySearchPos(spots, NumOfApart, SchoolPos),
        left = 0,
        right = NumOfApart,
        Ldelta,
        Rdelta,
        cur,
        BusCurCapacity;
    
    while(left < SchoolIdx || right > SchoolIdx){
        BusCurCapacity = BusCapacity;
        Ldelta = SchoolPos - spots[left].pos;
        Rdelta = spots[right].pos - SchoolPos;
        
        if(Ldelta > Rdelta
           || (Ldelta == Rdelta && spots[left].numOfStud >= spots[right].numOfStud)){
            //Bus Start
            cur = left;
            Movement += Ldelta;
            for(; BusCurCapacity > 0 && cur < SchoolIdx;){
                
                int& AmoutOfStud = spots[cur].numOfStud;
                
                if(AmoutOfStud == BusCurCapacity
                   || AmoutOfStud > BusCurCapacity){
                    AmoutOfStud -= BusCurCapacity;
                    BusCurCapacity = 0;
                    //Go School
                }else{
                    BusCurCapacity -= AmoutOfStud;
                    Movement += (spots[cur+1].pos - spots[cur].pos);
                    cur++;
                }
            }
            //Bus Back
            Movement += (SchoolPos - spots[cur].pos);
            left = cur;
            if(spots[left].numOfStud == 0) left++;
        }else{
            //Bus Start
            cur = right;
            Movement += Rdelta;
            for(; BusCurCapacity > 0 && cur > SchoolIdx;){
                
                int& AmoutOfStud = spots[cur].numOfStud;
                
                if(AmoutOfStud == BusCurCapacity
                   || AmoutOfStud > BusCurCapacity){
                    AmoutOfStud -= BusCurCapacity;
                    BusCurCapacity = 0;
                    //Go School
                }else{
                    BusCurCapacity -= AmoutOfStud;
                    Movement += (spots[cur].pos - spots[cur-1].pos);
                    cur--;
                }
            }
            //Bus Back
            Movement += (spots[cur].pos - SchoolPos);
            right = cur;
            if(spots[right].numOfStud == 0) right--;
        }
    }
    
    
    cout << Movement;
    
    return 0;
}
