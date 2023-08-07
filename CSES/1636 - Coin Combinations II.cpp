#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n, x;
  cin >> n >> x;

  vector<int> cv(n);
  for (auto& c : cv) cin >> c;

  vector<int> dp(x + 1);
  dp[0] = 1;

  for (int c : cv) {
    for (int i = 1; i <= x; i++) {
      if (c <= i) dp[i] = (dp[i] + dp[i - c]) % mod;
    }
  }

  cout << dp[x];
}
