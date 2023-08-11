#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> steps(n);
  for (int& s : steps) cin >> s;

  vector<bool> dp(k + 1, 0);

  for (int i = 0; i <= k; i++) {
    for (int s : steps) {
      if (i - s >= 0 && !dp[i - s]) {
        dp[i] = 1;
        break;
      }
    }
  }
  cout << (dp[k] ? "First" : "Second");
}
