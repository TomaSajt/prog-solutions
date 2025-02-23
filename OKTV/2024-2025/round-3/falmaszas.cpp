#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int INF = 1e9;

int32_t main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n, m;
  cin >> n >> m;

  vector<vector<int>> board(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> board[i][j];
    }
  }

  vector<array<int, 2>> dp(n, {INF, -1});
  dp[0] = {0, -2};

  for (int i = 1; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int a = board[i][j];
      if (a == 0 || i - a < 0) continue;
      if (dp[i][0] > dp[i - a][0] + 1) {
        dp[i] = {dp[i - a][0] + 1, j};
      }
    }
  }

  if (dp[n - 1][0] == INF) {
    cout << "-1";
    return 0;
  }

  cout << dp[n - 1][0] << endl;
  int i = n - 1;
  while (i != 0) {
    cout << dp[i][1] + 1 << ' ';
    i -= board[i][dp[i][1]];
  }
}
