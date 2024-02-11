#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

int solve(const vector<set<int>>& person_to_tshirts, int n) {
  vector<vector<int>> dp(101, vector<int>(1 << n)); // dp[i][mask]: number of ways to have bitset 'mask' if the highest id tshirt we can use is 'i'
  dp[0][0] = 1;
  for (int i = 1; i <= 100; i++) {
    dp[i][0] = 1;
    for (int mask = 1; mask < (1 << n); mask++) {
      dp[i][mask] = dp[i - 1][mask];
      for (int j = 0; j < n; j++) {
        if ((mask >> j & 1) == 0 || !person_to_tshirts[j].count(i)) continue;
        int prev_mask = mask - (1 << j);
        dp[i][mask] += dp[i - 1][prev_mask];
        dp[i][mask] %= MOD;
      }
    }
  }
  return dp[100][(1 << n) - 1];
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n >> ws;
    vector<set<int>> person_to_tshirts(n);
    for (int i = 0; i < n; i++) {
      string line;
      getline(cin, line);
      stringstream ss(line);
      int a;
      while (ss >> a) person_to_tshirts[i].insert(a);
    }
    cout << solve(person_to_tshirts, n) << '\n';
  }
}
