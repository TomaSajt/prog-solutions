#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);

  int n;
  cin >> n;

  vector<vector<bool>> board(n + 1, vector<bool>(n + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      char c;
      cin >> c;
      board[i][j] = c == '.';
    }
  }

  if (!board[1][1] || !board[n][n]) {
    cout << "0\n";
    return 0;
  }

  vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
  dp[1][1] = 1;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == 1 && j == 1) continue;
      if (board[i][j]) {
        dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
        dp[i][j] %= mod;
      }
    }
  }

  cout << dp[n][n] << endl;
}
