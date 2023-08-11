#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, b;
  cin >> n >> m >> b;

  vector<vector<int>> desert(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> desert[i][j];
    }
  }

  vector<vector<int>> dp(n, vector<int>(m, -1));
  dp[0][0] = desert[0][0];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (i > 0 && dp[i - 1][j] >= b) {
        dp[i][j] = max(dp[i][j], dp[i - 1][j] + desert[i][j] - b);
      }
      if (j > 0 && dp[i][j - 1] >= b) {
        dp[i][j] = max(dp[i][j], dp[i][j - 1] + desert[i][j] - b);
      }
    }
  }

  cout << dp[n - 1][m - 1] << '\n';
  if (dp[n - 1][m - 1] == -1) return 0;

  vector<char> sol;
  int ci = n - 1, cj = m - 1;
  while (ci > 0 || cj > 0) {
    if (cj == 0) {
      sol.push_back('L');
      ci--;
    }
    else if (ci == 0) {
      sol.push_back('J');
      cj--;
    }
    else if (dp[ci - 1][cj] > dp[ci][cj - 1]) {
      sol.push_back('L');
      ci--;
    }
    else {
      sol.push_back('J');
      cj--;
    }
  }

  reverse(sol.begin(), sol.end());
  for (char c : sol) cout << c;
}
