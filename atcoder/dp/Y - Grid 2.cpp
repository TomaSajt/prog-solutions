#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;

ll fact[200001];

ll mul(ll a, ll b) { return a * b % mod; }

ll pow(ll a, ll b) {
  if (b == 0) return 1;
  if (b % 2 == 1) return mul(pow(a, b - 1), a);
  return pow(mul(a, a), b / 2);
}

ll inv(ll a) { return pow(a, mod - 2); }

ll choose(ll n, ll k) { return mul(fact[n], inv(mul(fact[n - k], fact[k]))); }

ll sub(ll a, ll b) { return ((a - b) % mod + mod) % mod; }

int main() {
  fact[0] = 1;
  for (ll i = 1; i <= 200000; i++) fact[i] = mul(fact[i - 1], i);

  ios::sync_with_stdio(0);
  cin.tie(0);

  ll h, w, m;
  cin >> h >> w >> m;

  vector<array<ll, 2>> points(m);
  for (auto& [y, x] : points) {
    cin >> y >> x;
    y--, x--;
  }

  sort(points.begin(), points.end());

  points.push_back({h - 1, w - 1});

  vector<ll> dp(m + 1);
  for (ll i = 0; i <= m; i++) {
    auto& [cy, cx] = points[i];
    dp[i] = choose(cy + cx, cy);
    for (int j = 0; j < i; j++) {
      auto& [py, px] = points[j];
      ll dy = cy - py;
      ll dx = cx - px;
      if (dy < 0 || dx < 0) continue;
      dp[i] = sub(dp[i], dp[j] * choose(dy + dx, dy));
    }
  }

  cout << dp[m];
}
