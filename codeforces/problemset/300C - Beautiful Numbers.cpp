#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7, max_n = 1e6;
ll fact[max_n + 1], i_fact[max_n + 1];
bool is_fav[9 * max_n + 1];

ll mult(ll a, ll b) {
  return a * b % mod;
}

ll powi(ll a, ll b) {
  return b == 0 ? 1 : mult(powi(mult(a, a), b / 2), b % 2 == 0 ? 1 : a);
}

ll nCr(ll a, ll b) {
  return mult(fact[a], mult(i_fact[a - b], i_fact[b]));
}

int main() {
  int a, b, n;
  cin >> a >> b >> n;

  is_fav[0] = 1;
  for (int i = 1; i <= 9 * max_n; i++) {
    is_fav[i] = is_fav[i / 10] && (i % 10 == a || i % 10 == b);
  }

  fact[0] = 1;
  for (int i = 1; i <= max_n; i++) fact[i] = mult(fact[i - 1], i);
  i_fact[max_n] = powi(fact[max_n], mod - 2);
  for (int i = max_n - 1; i >= 0; i--) {
    i_fact[i] = mult(i_fact[i + 1], i + 1);
  }

  ll res = 0;
  for (int i = 0; i <= n; i++) {
    if (is_fav[a * i + b * (n - i)]) {
      res += nCr(n, i);
      res %= mod;
    }
  }

  cout << res;
}
