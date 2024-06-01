#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll X_MAX = 1e7;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  // ldp[i]: lowest prime divisor of i
  vector<ll> lpd(X_MAX + 1, -1);
  for (ll i = 2; i <= X_MAX; i++) {
    if (lpd[i] != -1) continue;
    lpd[i] = i;
    for (ll j = i * i; j <= X_MAX; j += i)
      if (lpd[j] == -1) lpd[j] = i;
  }

  // cnts[p]: number of x_i that p divides at least once
  vector<ll> cnts(X_MAX + 1, 0);

  ll n;
  cin >> n;
  while (n--) {
    ll x;
    cin >> x;
    while (x > 1) {
      ll p = lpd[x];
      cnts[p]++;
      while (x % p == 0) x /= p;
    }
  }

  vector<ll> cnts_pref(X_MAX + 1);
  partial_sum(cnts.begin(), cnts.end(), cnts_pref.begin());

  ll q;
  cin >> q;
  while (q--) {
    ll l, r;
    cin >> l >> r;
    l = min(l, X_MAX + 1), r = min(r, X_MAX);
    cout << cnts_pref[r] - cnts_pref[l - 1] << '\n';
  }
}
