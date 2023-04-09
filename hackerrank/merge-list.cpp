#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

ll fact_mod(ll n) {
  ll res = 1;
  for (int i = 2; i <= n; i++) {
    res *= i;
    res %= MOD;
  }
  return res;
}

ll pow_mod(ll b, ll e) {
  ll res = 1;
  while (e > 0) {
    if (e % 2 == 1) {
      res *= b;
      res %= MOD;
      e--;
    }
    e /= 2;
    b *= b;
    b %= MOD;
  }
  return res;
}

ll inverse_mod(ll a) { return pow_mod(a, MOD - 2); }

ll binomial_coefficient_mod(ll n, ll k) {
  ll b = (fact_mod(n - k) * fact_mod(k)) % MOD;
  return (fact_mod(n) * inverse_mod(b)) % MOD;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    cout << binomial_coefficient_mod(n + m, m) << '\n';
  }
}
