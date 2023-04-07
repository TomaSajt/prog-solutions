#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<int>> board(n + 1, vector<int>(m + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> board[i][j];
    }
  }

  // what is the min cost of getting to [i;j] with d dynamites
  vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(k + 1, INT_MAX / 2)));

  dp[1][1][0] = board[1][1];
  for (int d = 1; d <= k; d++)
    dp[1][1][d] = dp[1][1][d - 1] / 2;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      for (int d = 0; d <= k; d++) {
        for (int dd = 0; dd <= d; dd++) {
          dp[i][j][d] = min(dp[i][j][d], (board[i][j] >> dd) + min(dp[i][j - 1][d - dd], dp[i - 1][j][d - dd]));
        }
      }
    }
  }
  cout << dp[n][m][k];
}
