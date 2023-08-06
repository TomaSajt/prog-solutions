#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k = 2;
  cin >> n;

  vector<int> v(n + 1);
  for (int i = 1; i <= n; i++) cin >> v[i];

  vector<int> dp(n + 1, INT_MAX);
  dp[1] = 0;

  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= k; j++) {
      if (i - j >= 1) {
        dp[i] = min(dp[i], dp[i - j] + abs(v[i] - v[i - j]));
      }
    }
  }

  cout << dp[n] << endl;
}
