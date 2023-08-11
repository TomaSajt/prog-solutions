#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);

  int n;
  cin >> n;

  vector<double> probs(n + 1);
  for (int i = 1; i <= n; i++) cin >> probs[i];

  // dp[i][j] Probability of having j heads after using the the first i coins
  vector<vector<double>> dp(n + 1, vector<double>(n + 1));
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      dp[i][j] = dp[i - 1][j] * (1 - probs[i]);
      if (j > 0) dp[i][j] += dp[i - 1][j - 1] * probs[i];
    }
  }

  double res = 0;
  for (int i = n / 2 + 1; i <= n; i++) {
    res += dp[n][i];
  }

  cout << res;
}
