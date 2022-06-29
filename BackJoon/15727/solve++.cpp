#include <iostream>

#define LEN 5

using namespace std;

int main() {
    int A;
    cin >> A;
    cout << (A % LEN == 0 ? A / LEN : A / LEN + 1);
    return 0;
}
