#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#pragma GCC optimize ("Ofast")
using namespace std;

int main() {
    speed;
    int n, l, r, x, c = 0;
    cin >> n >> l >> r >> x;
    vector<int> a(n);
    for (int& v : a) cin >> v;
    for (int i = 1; i < 1 << n; i++) {
        int s = 0, mi = INT_MAX, ma = 0;
        for (int j = 0; j < n; j++) {
            if (i >> j & 1) {
                s += a[j];
                mi = min(mi, a[j]);
                ma = max(ma, a[j]);
            }
        }
        if (s >= l && s <= r && ma - mi >= x) c++;
    }
    cout << c << endl;
}