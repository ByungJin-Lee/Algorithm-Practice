#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    int A, B;
    cin >> A >> B;
    A = B - A;
    int g = gcd(A, B);
    cout << A / g << ' ' << B / g;
    return 0;
}
