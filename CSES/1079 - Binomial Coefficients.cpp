#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

ll fact[1000001];

ll pow_mod(ll b, ll e) {
  ll res = 1;
  while (e > 0) {
    if (e % 2 == 1) {
      res *= b;
      res %= MOD;
    }
    e /= 2;
    b *= b;
    b %= MOD;
  }
  return res;
}

ll inverse_mod(ll a) { return pow_mod(a, MOD - 2); }

ll binomial_coefficient_mod(ll n, ll k) {
  return (fact[n] * inverse_mod((fact[k] * fact[n - k]) % MOD)) % MOD;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  fact[0] = 1;
  for (int i = 1; i <= 1000000; i++) fact[i] = (fact[i - 1] * i) % MOD;
  while (n--) {
    ll a, b;
    cin >> a >> b;
    cout << binomial_coefficient_mod(a, b) << '\n';
  }
}
