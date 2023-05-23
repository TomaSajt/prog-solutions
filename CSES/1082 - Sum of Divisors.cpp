#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  ll n;
  cin >> n;
  ll s = 0;
  int k = 1;
  for (; n / k - n / (k + 1) > 0; k++) {
    ll x = (n / k - n / (k + 1)) % mod;
    ll a1 = n % (n / k);
    ll d = k % mod;
    s += (x * a1) % mod + (((x * (x - 1) / 2) % mod) * (d % mod)) % mod;
    s %= mod;
  }
  for (int i = n / k; i > 0; i--) {
    s += n % i;
    s %= mod;
  }
  n %= mod;
  s = (n * n % mod + mod - s) % mod;
  cout << s;
}
