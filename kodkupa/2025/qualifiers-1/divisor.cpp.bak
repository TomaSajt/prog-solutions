#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool bruh(ll l, ll r, ll div) {
  if (l % div == 0) return true;
  if (r % div == 0) return true;
  return l / div != r / div;
}

vector<ll> get_divisors(ll n) {
  vector<ll> divisors;
  for (ll i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      divisors.push_back(i);
      divisors.push_back(n / i);
    }
  }
  return divisors;
}

void solve() {
  ll a, b, k;
  cin >> a >> b >> k;
  vector<ll> divisors = get_divisors(a + b + k);
  sort(divisors.rbegin(), divisors.rend());
  for (ll& div : divisors) {
    if (bruh(a, a + k, div)) {
      cout << div << endl;
      return;
    }
  }
  cout << "NOOO" << endl;
  cout << 1 / 0;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
