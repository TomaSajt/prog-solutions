#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<double>> prob(n, vector<double>(n));
  for (auto& r : prob) {
    for (double& p : r) cin >> p;
  }

  vector<double> dp(1 << n);
  dp[(1 << n) - 1] = 1;
  for (int mask = (1 << n) - 1; mask >= 0; mask--) {
    int pc = __builtin_popcount(mask);
    if (pc < 2) continue;
    double base_prob = 2.0 / (pc * (pc - 1));
    for (int i = 0; i < n; i++) {
      if ((mask >> i & 1) == 0) continue;
      for (int j = 0; j < n; j++) {
        if (i == j || (mask >> j & 1) == 0) continue;
        int new_mask = mask - (1 << j);
        dp[new_mask] += dp[mask] * prob[i][j] * base_prob;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cout << dp[1 << i] << ' ';
  }
}
