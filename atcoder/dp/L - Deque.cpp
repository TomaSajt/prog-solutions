#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(int l, int r, const vector<ll>& a, vector<vector<ll>>& dp) {
  if (dp[l][r] != -1) return dp[l][r];
  if (l == r) return dp[l][r] = a[l];
  ll res = max(a[l] - solve(l + 1, r, a, dp), a[r] - solve(l, r - 1, a, dp));
  return dp[l][r] = res;
}

int main() {
  int n;
  cin >> n;

  vector<ll> a(n);
  for (ll& ai : a) cin >> ai;

  vector<vector<ll>> dp(n, vector<ll>(n, -1));
  cout << solve(0, n - 1, a, dp);
}
