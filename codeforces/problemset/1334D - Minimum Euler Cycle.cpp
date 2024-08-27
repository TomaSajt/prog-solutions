#include <bits/stdc++.h>
using ll = long long;
using namespace std;

ll calc(ll n, ll k) {
  return (2 * n - k - 1) * k;
}

// returns lowest k where calc(n,k) is >=a
ll bsearch(ll n, ll a) {
  ll bad = 0, good = n;
  while (good - bad > 1) {
    ll m = (bad + good) / 2;
    if (calc(n, m) < a) bad = m;
    else good = m;
  }
  return good;
}

ll get(ll n, ll a) {
  if (a > n * (n - 1)) return 1;
  ll c = bsearch(n, a);
  ll pr = a - calc(n, c - 1) - 1;
  return pr % 2 == 0 ? c : pr / 2 + c + 1;
}

int main() {
  ll t;
  cin >> t;
  while (t--) {
    ll n, l, r;
    cin >> n >> l >> r;
    for (ll i = l; i <= r; i++) {
      cout << get(n, i) << ' ';
    }
    cout << '\n';
  }
}
