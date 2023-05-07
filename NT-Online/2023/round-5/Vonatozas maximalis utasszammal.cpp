#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n;
  cin >> n;
  vector<vector<int>> cnt(2, vector<int>(n));
  for (int& c : cnt[0]) cin >> c;
  for (int& c : cnt[1]) cin >> c;
  vector<vector<vector<ll>>> range_income(
      2, vector<vector<ll>>(n, vector<ll>(n + 1)));
  for (int g = 0; g < 2; g++) {
    for (int s = 0; s < n; s++) {
      range_income[g][s][s] = 0;
      ll acc_cnt = 0;
      for (int e = s + 1; e <= n; e++) {
        acc_cnt += cnt[g][e - 1];
        range_income[g][s][e] = range_income[g][s][e - 1] + acc_cnt;
      }
    }
  }

  vector<vector<ll>> dp(2, vector<ll>(n + 1));
  dp[0][0] = 0;
  dp[1][0] = 0;
  for (int p = 1; p <= n; p++) {
    for (int g = 0; g < 2; g++) {
      dp[g][p] = 0;
      for (int x = 0; x < p; x++) {
        dp[g][p] = max(dp[g][p], dp[1 - g][x] + range_income[g][x][p]);
      }
    }
  }
  cout << max(dp[0][n], dp[1][n]);
  return 0;
}
