#include <bits/stdc++.h>
#define int int64_t

using namespace std;

int n;
int v[400001], pref[400001], dp[400001];
// dp[i] num layers if i was the last used pos

int32_t main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> v[i];
  for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] + v[i];

  for (int i = 1; i <= n; i++) {
    dp[i] = LLONG_MIN;
    for (int j = 0; j < i; j++) {
      int sum = pref[i] - pref[j];
      if (sum <= 0) continue;
      dp[i] = max(dp[i], dp[j] + 1);
    }
  }
  cout << dp[n];
}
