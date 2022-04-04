#include <iostream>
#include <cstring>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    bool IsPrime[1000001];
    memset(IsPrime, true, sizeof(IsPrime));

    for (unsigned int i = 2; i <= 1000; i++){
        for (unsigned int j = 2; i * j <= 1000000; j++) IsPrime[i*j] = false;
    }

    int T, V, C;

    cin >> T;

    while (T-- != 0){
        C = 0;
        cin >> V;

        for (unsigned int a = 2, r = V / 2; a <= r; a++){
            if (IsPrime[a] && IsPrime[V - a]) C++;
        }
        cout << C << '\n';
    }

    return 0;
}
