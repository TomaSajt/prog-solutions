#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> coins(n);
  for (int& c : coins) cin >> c;

  vector<bool> dp(100001);
  dp[0] = 1;
  for (int c : coins) {
    for (int s = 100000; s >= 0; s--) {
      if (s - c >= 0 && dp[s - c]) dp[s] = 1;
    }
  }

  cout << count(dp.begin() + 1, dp.end(), 1) << '\n';
  for (int i = 1; i <= 100000; i++) {
    if (dp[i]) {
      cout << i << ' ';
    }
  }
}
