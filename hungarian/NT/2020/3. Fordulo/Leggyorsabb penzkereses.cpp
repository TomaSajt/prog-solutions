#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

int main() {
    speed;
    int n, p, l = 0, r = 0, best = INT_MAX, s = 0;
    cin >> n >> p;
    vector<int> v(n);
    for (int& a : v) cin >> a;
    while (l < n) {
        while (s < p && r < n) s += v[r++];
        if (s >= p) best = min(best, r - l);
        s -= v[l++];
    }
    cout << best;
}