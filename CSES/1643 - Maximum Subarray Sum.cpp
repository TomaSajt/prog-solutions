#include <bits/stdc++.h>
using namespace std;

int main() {
    long long a, s = 0, m = 0, x = LLONG_MIN;
    cin >> a;
    while (cin >> a) x = max(x, a), m = max(m, s = max(0ll, s + a));
    cout << (x < 0 ? x : m);
}