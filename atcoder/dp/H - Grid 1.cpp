#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main() {
  int h, w;
  cin >> h >> w;

  vector<vector<bool>> wall(h + 1, vector<bool>(w + 1));
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      char c;
      cin >> c;
      wall[i][j] = c == '#';
    }
  }

  vector<vector<int>> dp(h + 1, vector<int>(w + 1, 0));
  dp[1][1] = 1;

  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      if (wall[i][j]) continue;
      dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
      dp[i][j] %= mod;
    }
  }

  cout << dp[h][w];
}
