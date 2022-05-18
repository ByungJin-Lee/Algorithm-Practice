#include <iostream>
#include <cstring>

using namespace std;

typedef struct tagPattern { tagPattern* next[2]; bool IsLeaf; } Pattern;

Pattern p[9];

void InitPattern(){
    memset(p, 0, sizeof(p));

    Pattern* cur = &p[0];

    p[0].next[0] = &p[7];
    p[0].next[1] = &p[1];

    p[1].next[0] = &p[2];

    p[2].next[0] = &p[3];

    p[3].next[0] = &p[3];
    p[3].next[1] = &p[4];

    p[4].next[0] = &p[7];
    p[4].next[1] = &p[5];
    p[4].IsLeaf = true;

    p[5].next[0] = &p[6];
    p[5].next[1] = &p[5];
    p[5].IsLeaf = true;

    p[6].next[0] = &p[3];
    p[6].next[1] = &p[8];

    p[7].next[1] = &p[8];

    p[8].next[0] = &p[7];
    p[8].next[1] = &p[1];
    p[8].IsLeaf = true;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    InitPattern();

    int T;
    char record[201];

    cin >> T;

    while (T-- != 0){
        cin >> record;
        bool IsMatch = false;
        Pattern* cur = &p[0];
        for (int i = 0; record[i] != 0; i++){
            if (cur->next[record[i] - '0'] == 0) {
                IsMatch = false; break;
            }
            cur = cur->next[record[i] - '0'];
            IsMatch = cur->IsLeaf;
        }
        cout << (IsMatch ? "YES\n" : "NO\n");
    }
    return 0;
}
