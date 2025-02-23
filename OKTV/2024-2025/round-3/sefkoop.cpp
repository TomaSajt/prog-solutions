// NOT CORRECT!!!

#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int INF = 1e9;

int32_t main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n;
  cin >> n;
  vector<array<int, 2>> X(n + 1);
  for (int i = 1; i <= n; i++) cin >> X[i][0];
  for (int i = 1; i <= n; i++) cin >> X[i][1];

  vector<int> dp(n + 1);
  dp[0] = 0;

  auto calc_dp_sided = [&](int m, int start_c) {
    array<int, 2> sizes = {0, 0};
    sizes[start_c] = X[m][start_c];

    int sol = INF;
    for (int i = m - 1; i >= 0; i--) {
      int a = 0, b = 1;
      if (sizes[a] < sizes[b]) swap(a, b);
      sol = min(sol, dp[i] + sizes[a]);
      if (i > 0) sizes[b] += X[i][b];
    }

    return sol;
  };

  for (int i = 1; i <= n; i++) {
    dp[i] = min(calc_dp_sided(i, 0), calc_dp_sided(i, 1));
  }
  cout << dp[n];
}
