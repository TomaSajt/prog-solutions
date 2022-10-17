#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;

int main() {
    speed;
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (auto& a : v) cin >> a;
    vector<vector<ll>> dp(n, vector<ll>(m + 1, 0));
    if (v[0] != 0) dp[0][v[0]] = 1;
    else {
        for (int j = 1; j <= m; j++) {
            dp[0][j] = 1;
        }
    }
    for (int i = 1; i < n; i++) {
        if (v[i] != 0) {
            int a = v[i];
            dp[i][a] = dp[i - 1][a];
            if (a != 1) dp[i][a] += dp[i - 1][a - 1];
            if (a != m) dp[i][a] += dp[i - 1][a + 1];
            dp[i][a] %= mod;
        }
        else {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j != 1) dp[i][j] += dp[i - 1][j - 1];
                if (j != m) dp[i][j] += dp[i - 1][j + 1];
                dp[i][j] %= mod;
            }
        }
    }
    ll res = 0;
    for (int j = 0; j <= m; j++) {
        res += dp[n - 1][j];
        res %= mod;
    }
    cout << res;
}