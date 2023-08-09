#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<array<int, 3>> happy(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> happy[i][0] >> happy[i][1] >> happy[i][2];
  }

  vector<array<int, 3>> dp(n + 1, {0, 0, 0});
  for (int i = 1; i <= n; i++) {
    dp[i][0] = happy[i][0] + max(dp[i - 1][1], dp[i - 1][2]);
    dp[i][1] = happy[i][1] + max(dp[i - 1][0], dp[i - 1][2]);
    dp[i][2] = happy[i][2] + max(dp[i - 1][0], dp[i - 1][1]);
  }

  cout << max({dp[n][0], dp[n][1], dp[n][2]});
}
