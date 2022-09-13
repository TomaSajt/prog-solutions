#include <bits/stdc++.h>
using namespace std;

int main() {
    long long a = 0, b, r = 0;
    cin >> b;
    while (cin >> b) {
        r += max(0ll, a - b);
        a = max(b, a);
    }
    cout << r;
}