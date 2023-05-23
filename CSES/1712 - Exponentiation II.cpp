#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

ll pow_mod(ll b, ll e, ll p) {
  ll res = 1;
  b %= p;
  e %= p;
  while (e > 0) {
    if (e % 2 == 1) {
      res *= b;
      res %= p;
      e--;
    }
    b *= b;
    b %= p;
    e /= 2;
  }
  return res;
}

int main() {
  int n;
  cin >> n;
  while (n--) {
    ll a, b, c;
    cin >> a >> b >> c;
    cout << pow_mod(a, pow_mod(b, c, mod - 1), mod) << '\n';
  }
}
