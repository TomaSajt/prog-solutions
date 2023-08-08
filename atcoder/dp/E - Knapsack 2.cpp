#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int v_max = 1000;

int main() {
  ll n, W;
  cin >> n >> W;

  vector<ll> v(n + 1), w(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> w[i] >> v[i];
  }

  vector<vector<ll>> dp(n + 1, vector<ll>(n * v_max + 1, LONG_LONG_MAX / 2));
  dp[0][0] = 0;

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= n * v_max; j++) {
      dp[i][j] = dp[i - 1][j];
      if (j < v[i]) continue;
      dp[i][j] = min(dp[i][j], dp[i - 1][j - v[i]] + w[i]);
    }
  }

  for (int j = n * v_max;; j--) {
    if (dp[n][j] > W) continue;
    cout << j << endl;
    break;
  }
}
