#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;
#define int long long

signed main() {
    speed;
    int n, d;
    cin >> n >> d;
    vector<int> x(n);
    for (auto& a : x) cin >> a;
    int res = 0;
    int l = 0, r = 1;
    while (l < n - 1) {
        while (r < n && x[r] - x[l] <= d) r++;
        res += (r - l - 1) * (r - l - 2) / 2;
        l++;
    }
    cout << res << endl;
}