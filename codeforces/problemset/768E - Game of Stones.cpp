#include <bits/stdc++.h>
using namespace std;

/*
using ll = long long;
map<ll, int> dp[61];

int solve(int rem, ll mask = 0) {
  if (rem == 0) return 0;
  if (dp[rem].count(mask)) return dp[rem][mask];
  set<int> mex_inputs;
  for (int d = 1; d <= rem; d++) {
    if ((mask >> d) & 1) continue;
    ll new_mask = mask | (1ll << d);
    int new_rem = rem - d;
    mex_inputs.insert(solve(new_rem, new_mask));
  }
  auto it = mex_inputs.begin();
  for (int i = 0; i < mex_inputs.size(); i++, it++) {
    if (i != *it) return dp[rem][mask] = i;
  }
  return dp[rem][mask] = mex_inputs.size();
}
*/

// x*(x+1)/2 = s
int solve(int s) {
  return (sqrt(8 * s + 1) - 1) * 0.5;
}

int main() {
  int n;
  cin >> n;
  int res = 0;
  while (n--) {
    int s;
    cin >> s;
    res ^= solve(s); // grundi number for pile of size s
  }
  cout << (res == 0 ? "YES" : "NO");
}
