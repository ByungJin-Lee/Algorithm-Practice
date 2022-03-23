#include <iostream>
#include <algorithm>

using namespace std;

typedef struct {int l, r;} Rank;

bool Cmp(Rank& lhs, Rank& rhs) {return lhs.l < rhs.l;}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    Rank people[100000];
    
    int T, N;
    
    cin >> T;
    
    while(T-- != 0){
        cin >> N;
        for(int i = 0; i < N; i++)
            cin >> people[i].l >> people[i].r;
        sort(people, people+N, Cmp);
        int num = 0, cut = 100001;
        for(int i = 0; i < N; i++){
            if(people[i].r < cut){
                cut = people[i].r;
                num++;
            }
        }
        cout << num << '\n';
    }
    return 0;
}
