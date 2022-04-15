#include <iostream>

using namespace std;

int top;

void move(int l, int s, int d){
    if (l > top) return;
    int dest = 6 - s - d;
    move(l + 1, s, dest);
    cout << s << ' ' << d << '\n';
    move(l + 1, dest, d);
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> top;
    cout << (1 << top) - 1 << '\n';
    move(1, 1, 3);

    return 0;
}
