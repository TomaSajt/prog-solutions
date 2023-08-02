#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 20210108;

int main() {
  int n;
  cin >> n;
  vector<ll> dp(n + 1);
  dp[0] = 1;
  for (int i = 1; i <= n; i++) {
    dp[i] = 3 * dp[i - 1];
    if (i >= 2) dp[i] += dp[i - 2];
    dp[i] %= MOD;
  }
  cout << dp[n];
}
