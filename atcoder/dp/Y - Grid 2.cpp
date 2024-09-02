#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;
const ll L = 1e5;

ll fact[L + 1], inv_fact[L + 1];

ll modpow(ll a, ll b) {
  if (b == 0) return 1;
  return modpow(a * a % mod, b / 2) * (b % 2 == 1 ? a : 1) % mod;
}

ll choose(ll n, ll k) {
  return fact[n] * inv_fact[n - k] % mod * inv_fact[k] % mod;
}

int main() {
  fact[0] = 1;
  for (int i = 1; i <= L; i++) fact[i] = fact[i - 1] * i % mod;
  inv_fact[L] = modpow(fact[L], mod - 2);
  for (ll i = L; i >= 1; i--) inv_fact[i - 1] = inv_fact[i] * i % mod;

  ll h, w, n;
  cin >> h >> w >> n;

  vector<array<ll, 2>> points(n);
  for (auto& [r, c] : points) cin >> r >> c;

  // make sure a point has all the points from where it could be reached before it
  sort(points.begin(), points.end());
  points.push_back({h, w});

  // number of ways to get from (1,1) to points[i] without passing through any points[j] j<i
  vector<ll> dp(n + 1);

  for (ll i = 0; i <= n; i++) {
    auto& [r1, c1] = points[i];
    dp[i] = choose(r1 - 1 + c1 - 1, r1 - 1);
    for (ll j = 0; j < i; j++) {
      auto& [r2, c2] = points[j];
      if (c2 > c1) continue;
      dp[i] -= dp[j] * choose(r1 - r2 + c1 - c2, r1 - r2) % mod;
      dp[i] %= mod;
    }
    if (dp[i] < 0) dp[i] += mod;
  }

  cout << dp[n];
}
