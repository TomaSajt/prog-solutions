#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  ll n, m;
  cin >> n >> m;
  vector<ll> t(n);
  for (ll& ti : t) cin >> ti;

  auto check = [&](ll k) {
    ll res = 0;
    for (ll ti : t) {
      res += k / ti;
      if (res >= m + 1) return true;
    }
    return false;
  };

  ll known_bad = 0, known_good = LLONG_MAX / 4;
  while (known_good - known_bad > 1) {
    ll k = (known_bad + known_good) / 2;
    if (check(k)) known_good = k;
    else known_bad = k;
  }

  cout << known_good;
}
