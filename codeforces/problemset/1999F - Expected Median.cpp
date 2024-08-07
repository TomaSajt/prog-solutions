#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

ll fact[200001], inv_fact[200001];

ll mul(ll a, ll b) { return a * b % mod; }

ll pow(ll a, ll b) {
  if (b == 0) return 1;
  if (b % 2 == 1) return mul(pow(a, b - 1), a);
  return pow(mul(a, a), b / 2);
}

ll inv(ll a) { return pow(a, mod - 2); }

ll choose(ll n, ll k) { return n < k ? 0 : mul(fact[n], mul(inv_fact[n - k], inv_fact[k])); }

void solve() {
  int n, k;
  cin >> n >> k;

  int c = 0;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    c += a;
  }

  ll res = 0;
  for (int i = k / 2 + 1; i <= k; i++) {
    res += mul(choose(c, i), choose(n - c, k - i));
    res %= mod;
  }

  cout << res << endl;
}

int main() {
  fact[0] = 1;
  for (ll i = 1; i <= 200000; i++) fact[i] = mul(fact[i - 1], i);
  inv_fact[200000] = inv(fact[200000]);
  for (ll i = 200000; i >= 1; i--) inv_fact[i - 1] = mul(inv_fact[i], i);

  ios::sync_with_stdio(0), cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
}
