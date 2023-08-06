#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int n, w_max;
  cin >> n >> w_max;

  vector<ll> w(n + 1), v(n + 1);
  for (int i = 1; i <= n; i++) cin >> w[i] >> v[i];

  vector<vector<ll>> dp(n + 1, vector<ll>(w_max + 1, 0));
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= w_max; j++) {
      dp[i][j] = dp[i - 1][j];
      if (j - w[i] >= 0) {
        dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
      }
    }
  }

  cout << dp[n][w_max] << endl;

  /*
  vector<ll> dp(w_max + 1, 0);
  for (int i = 1; i <= n; i++) {
    for (int j = w_max; j >= 0; j--) {
      if (j - w[i] >= 0) {
        dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
      }
    }
  }

  cout << dp[w_max] << endl;
  */
}
