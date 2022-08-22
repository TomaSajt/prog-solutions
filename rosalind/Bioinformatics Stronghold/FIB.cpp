#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, k;
    cin >> n >> k;
    vector<ll> v(n + 1);
    v[1] = 1;
    for (int i = 2; i <= n; i++) {
        v[i] = k * v[i - 2] + v[i - 1];
    }
    cout << v[n] << '\n';
}