#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;
typedef long long ll;

int main() {
    speed;

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> sat(n);
    for (auto& a : sat) cin >> a;

    vector<vector<int>> bonus(n, vector<int>(n, 0));
    while (k--) {
        int u, v;
        cin >> u >> v;
        cin >> bonus[u - 1][v - 1];
    }

    // dp[st][d] = max satisfaction achievable having eaten dishes maked by the bitset `st` and having last eaten dish `d`
    vector<vector<ll>> dp(1 << n, vector<ll>(n, 0));

    for (int d = 0; d < n; d++) {
        dp[1 << d][d] = sat[d];
    }

    ll res = 0;
    for (int cst = 0; cst < 1 << n; cst++) {
        if (__builtin_popcount(cst) > m) continue;
        for (int cd = 0; cd < n; cd++) {
            if (!(cst & (1 << cd))) continue;
            int pst = cst - (1 << cd);
            for (int pd = 0; pd < n; pd++) {
                if (!(pst & (1 << pd))) continue;
                dp[cst][cd] = max(dp[cst][cd], dp[pst][pd] + bonus[pd][cd] + sat[cd]);
            }
            res = max(res, dp[cst][cd]);
        }
    }
    cout << res;
}