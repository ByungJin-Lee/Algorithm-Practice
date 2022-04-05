#include <iostream>
#include <cstring>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    bool IsPrime[246913];
    memset(IsPrime, true, sizeof(IsPrime));
    IsPrime[1] = false;

    for (unsigned int i = 2; i <= 496; i++){
        for (unsigned int j = 2; i * j <= 246912; j++) IsPrime[i*j] = false;
    }
    
    int V, C;
    
    while (true){
        C = 0;
        cin >> V;
        if(V == 0) break;
        for (unsigned int a = V + 1, r = 2 * V; a <= r; a++)
            if (IsPrime[a]) C++;
        cout << C << '\n';
    }

    return 0;
}
