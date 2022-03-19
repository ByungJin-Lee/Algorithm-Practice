#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct {int seq, age; string name;} Member;

bool Cmp(Member& lhs, Member& rhs){
    if(lhs.age == rhs.age) return lhs.seq < rhs.seq;
    return lhs.age < rhs.age;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    vector<Member> members;
    Member m;
    
    cin >> N;
    
    for(int i = 0; i < N; i++){
        cin >> m.age;
        cin >> m.name;
        m.seq = i;
        members.push_back(m);
    }
    sort(members.begin(), members.end(), Cmp);
    
    for(Member& p : members)
        cout << p.age << ' ' << p.name << '\n';
    
    return 0;
}
