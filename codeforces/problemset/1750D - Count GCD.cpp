#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// how many integers x (x<=h) have gcd(k,x)=1
ll count(ll h, ll k) {
  if (k == 1) return h;
  ll cnt = h;

  vector<ll> pv;
  ll r = k;
  for (ll p = 2; p * p <= k; p++) {
    if (r % p != 0) continue;
    pv.push_back(p);
    while (r % p == 0) r /= p;
  }
  if (r != 1) pv.push_back(r);

  for (ll mask = 1; mask < (1ll << pv.size()); mask++) {
    ll prod = 1;
    for (int i = 0; i < pv.size(); i++) {
      if ((mask >> i) & 1) prod *= pv[i];
    }
    ll c = h / prod;
    if (__builtin_popcount(mask) % 2 == 1) cnt -= c;
    else cnt += c;
  }
  return cnt;
}

ll solve() {
  int n, m;
  cin >> n >> m;
  vector<ll> a(n);
  for (ll& ai : a) cin >> ai;
  ll res = 1;
  for (int i = 0; i < n - 1; i++) {
    if (a[i] % a[i + 1] != 0) return 0;
    res *= count(m / a[i + 1], a[i] / a[i + 1]);
    res %= 998244353;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int t;
  cin >> t;
  while (t--) cout << solve() << endl;
}
