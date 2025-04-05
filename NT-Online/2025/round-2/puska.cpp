#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, l;
  cin >> n >> l;
  vector<int> cost(n + 1), val(n + 1);
  for (int i = 1; i <= n; i++) cin >> cost[i] >> val[i];
  vector<vector<int>> dp(n + 1, vector<int>(l + 1, INT_MIN)); // using upto first i things costing exactly j
  dp[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= l; j++) {
      dp[i][j] = dp[i - 1][j];
      if (j - cost[i] >= 0) dp[i][j] = max(dp[i][j], dp[i - 1][j - cost[i]] + val[i]);
    }
  }

  int jj = max_element(dp[n].begin(), dp[n].end()) - dp[n].begin();
  int m = dp[n][jj];
  vector<int> used;
  for (int i = n; i > 0; i--) {
    if (dp[i - 1][jj] == dp[i][jj]) continue;
    used.push_back(i);
    jj -= cost[i];
  }
  cout << used.size() << ' ' << m << '\n';
  for (auto k : used) cout << k << ' ';
}
