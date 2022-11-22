#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

int main() {
    speed;
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (auto& a : v) cin >> a;
    sort(v.begin(), v.end());
    while (q--) {
        int a, b;
        cin >> a >> b;
        int l = abs(a - b);
        int r = a + b;
        auto lit = upper_bound(v.begin(), v.end(), l);
        auto rit = lower_bound(v.begin(), v.end(), r);
        cout << rit - lit << '\n';
    }
}