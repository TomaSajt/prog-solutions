#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;
const int maxN = 1e6, mod = 1e9 + 7;
long long a[maxN + 1], b[maxN + 1];
int main() {
    speed;
    a[1] = 1;
    b[1] = 1;
    for (int i = 2; i <= maxN; i++) {
        a[i] = (2 * a[i - 1] + b[i - 1]) % mod;
        b[i] = (4 * b[i - 1] + a[i - 1]) % mod;
    }
    int n;
    cin >> n;
    while (cin >> n) cout << (a[n] + b[n]) % mod << '\n';
}