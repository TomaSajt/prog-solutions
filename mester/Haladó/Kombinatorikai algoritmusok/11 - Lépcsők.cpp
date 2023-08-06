#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> dp(n + 1);
  dp[0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int d = 1; d <= k; d++) {
      if (i - d >= 0) {
        dp[i] += dp[i - d];
      }
    }
  }
  cout << dp[n];
}
