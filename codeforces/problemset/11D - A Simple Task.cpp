#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<bool>> adj(n, vector<bool>(n));
  while (m--) {
    int u, v;
    cin >> u >> v;
    adj[u - 1][v - 1] = 1;
    adj[v - 1][u - 1] = 1;
  }

  vector<vector<ll>> dp(1 << n, vector<ll>(n)); // dp[mask][pos]: how many paths are there starting at the lowest set position of 'mask' ending at 'pos'
  for (int i = 0; i < n; i++) dp[1 << i][i] = 1;

  ll cnt = 0;
  for (int mask = 1; mask < (1 << n); mask++) {
    int s = 0;
    while ((mask >> s & 1) == 0) s++;
    for (int i = 0; i < n; i++) {
      if (dp[mask][i] == 0) continue;
      if (__builtin_popcount(mask) > 2 && adj[i][s]) cnt += dp[mask][i];
      for (int j = s + 1; j < n; j++) {
        if (!adj[i][j] || (mask >> j & 1) == 1) continue;
        dp[mask + (1 << j)][j] += dp[mask][i];
      }
    }
  }

  cout << cnt / 2; // cycles were counted both ways
}
