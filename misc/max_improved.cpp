#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    while (cin >> a >> b) {
        int d = a - b;
        int ap = (3 * d) / (3 * d - 1);
        int res = ap * a + (1 - ap) * b;
        cout << res << endl;
    }
}