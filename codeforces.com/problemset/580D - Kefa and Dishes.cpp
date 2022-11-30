#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;
typedef long long ll;

int main() {
    speed;
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> vals(n);
    vector<vector<ll>> bonus(n, vector<ll>(n)), dp(1 << n, vector<ll>(n));
    for (ll& a : vals) cin >> a;
    while (k--) {
        int u, v, w;
        cin >> u >> v >> w;
        bonus[u - 1][v - 1] = w;
    }
    for (int i = 0; i < n; i++) {
        dp[1 << i][i] = vals[i];
    }
    ll res = 0;
    for (int st = 1; st < (1 << n); st++) {
        if (__builtin_popcount(st) > m) continue;
        for (int p1 = 0; p1 < n; p1++) {
            if (!(st >> p1 & 1)) continue;
            res = max(res, dp[st][p1]);
            for (int p0 = 0; p0 < n; p0++) {
                if (st >> p0 & 1) continue;
                int nst = st | (1 << p0);
                dp[nst][p0] = max(dp[nst][p0], dp[st][p1] + bonus[p1][p0] + vals[p0]);
            }
        }
    }
    cout << res;
}