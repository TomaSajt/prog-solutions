#include <bits/stdc++.h>
using namespace std;

int main() {
  string s1, s2;
  cin >> s1 >> s2;
  int n = s1.size(), m = s2.size();
  s1 = " " + s1;
  s2 = " " + s2;

  vector<vector<int>> dp(n + 1, vector<int>(m + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s1[i] == s2[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
      else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }
  }

  vector<char> res;
  int u = n, v = m;
  while (u > 0 && v > 0) {
    if (dp[u - 1][v] == dp[u][v]) {
      res.push_back(s1[u]);
      u--;
    }
    else if (dp[u][v - 1] == dp[u][v]) {
      res.push_back(s2[v]);
      v--;
    }
    else {
      assert(dp[u][v] == dp[u - 1][v - 1] + 1);
      res.push_back(s1[u]);
      u--, v--;
    }
  }
  while (u > 0) {
    res.push_back(s1[u]);
    u--;
  }
  while (v > 0) {
    res.push_back(s2[v]);
    v--;
  }
  cout << string(res.rbegin(), res.rend());
}
