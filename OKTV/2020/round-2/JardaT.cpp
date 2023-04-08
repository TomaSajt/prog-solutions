#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;
const int mod = 20200111;

int main() {
    speed;
    int n; cin >> n;
    vector<long long> a(n + 1), b(n + 1);
    a[0] = 1;
    a[1] = 1;
    b[0] = 0;
    b[1] = 2;
    for (int i = 2; i <= n; i++) {
        a[i] = (a[i - 1] + a[i - 2] + b[i - 2]) % mod;
        b[i] = (b[i - 1] + b[i - 2] + 2 * a[i - 1]) % mod;
    }
    cout << a[n];
}