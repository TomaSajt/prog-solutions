#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k, m = 0; cin >> n >> k;
    vector<int> cols(k, INT_MAX), pos(n);
    for (int i = 0, a, p; i < n;i++) {
        cin >> a;
        p = lower_bound(cols.begin(), cols.end(), a) - cols.begin();
        pos[i] = p;
        cols[p] = a;
        m = max(m, p);
    }
    cout << m + 1 << '\n';
    for (int i : pos) cout << i + 1 << ' ';
}