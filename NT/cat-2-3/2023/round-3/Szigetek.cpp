#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0), cin.sync_with_stdio(0);

  int n;
  cin >> n;

  vector<int> costs(n);
  for (int& a : costs) cin >> a;

  vector<int> dp(n);
  dp[0] = costs[0];
  dp[1] = dp[0] + costs[1];

  for (int i = 2; i < n; i++) {
    dp[i] = min(dp[i - 2], dp[i - 1]) + costs[i];
  }

  cout << dp.back();
}
