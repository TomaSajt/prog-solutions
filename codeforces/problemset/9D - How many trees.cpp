#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int N, D;
  cin >> N >> D;

  vector<vector<ll>> dp(N + 1, vector<ll>(N + 1)); // dp[n][d]: number of binary trees with node count `n` and depth `d`
  dp[0][0] = 1;

  for (int n = 1; n <= N; n++) {
    for (int d = 1; d <= N; d++) {
      for (int ln = 0; ln < n; ln++) {
        int rn = n - ln - 1;
        // case 1: left subtree depth = d-1, right subtree depth <= d-1
        for (int rd = 0; rd <= d - 1; rd++) {
          dp[n][d] += dp[ln][d - 1] * dp[rn][rd];
        }
        // case 2: right subtree depth = d-1, left subtree depth < d-1
        for (int ld = 0; ld < d - 1; ld++) {
          dp[n][d] += dp[ln][ld] * dp[rn][d - 1];
        }
      }
    }
  }

  cout << accumulate(dp[N].begin() + D, dp[N].end(), 0ll);
}
