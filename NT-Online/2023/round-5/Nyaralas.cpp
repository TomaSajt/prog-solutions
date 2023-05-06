#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, m;
  cin >> n >> k >> m;
  vector<int> v(n);
  for (int& a : v) cin >> a;
  vector<int> part_sum(n + 1);
  partial_sum(v.begin(), v.end(), part_sum.begin() + 1);
  vector<int> chunk_sums(n - m + 1);
  for (int i = 0; i <= n - m; i++)
    chunk_sums[i] = part_sum[i + m] - part_sum[i];
  // minimum cost of choosing k-i intervals of length m starting at position j
  vector<vector<int>> dp(k + 1, vector<int>(n + 1, INT_MAX / 2));
  dp[0][0] = 0;
  for (int i = 0; i <= k; i++) {
    for (int j = 0; j <= n; j++) {
      if (j > 0) dp[i][j] = min(dp[i][j], dp[i][j - 1]);
      if (i > 0 && j >= m)
        dp[i][j] = min(dp[i][j], dp[i - 1][j - m] + chunk_sums[j - m]);
    }
  }
  cout << dp[k][n];
}
