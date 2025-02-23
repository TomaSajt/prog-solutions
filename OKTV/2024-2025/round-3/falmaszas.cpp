#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int INF = LLONG_MAX;

vector<map<int, int>> g;

int32_t main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n, m;
  cin >> n >> m;
  g.resize(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int a;
      cin >> a;
      if (a == 0) continue;
      if (i - a >= 0) g[i][i - a] = j;
    }
  }

  vector<int> dp(n, INF);
  vector<array<int, 2>> to_here(n, {-1, -1});
  to_here[n - 1] = {-2, -2};
  dp[n - 1] = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (dp[i] == INF) continue;
    for (auto [nei, col] : g[i]) {
      if (dp[nei] > dp[i] + 1) {
        dp[nei] = dp[i] + 1;
        to_here[nei] = {i, col};
      }
    }
  }
  if (to_here[0][0] == -1) cout << "-1";
  else {
    cout << dp[0] << endl;
    int p = 0;
    stack<int> res;
    while (p != n - 1) {
      res.push(to_here[p][1]);
      p = to_here[p][0];
    }
    while (!res.empty()) {
      cout << res.top() + 1 << ' ';
      res.pop();
    }
  }
}
