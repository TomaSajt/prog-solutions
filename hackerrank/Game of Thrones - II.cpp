#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

ll fact[50001];

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

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  fact[0] = 1;
  for (int i = 1; i <= 50000; i++) fact[i] = (fact[i - 1] * i) % MOD;
  map<char, int> cnts;
  int cnt = 0;
  for (auto ch : s) cnts[ch]++, cnt++;
  ll top = fact[cnt / 2];
  ll bottom = 1;
  for (auto& [k, c] : cnts) {
    bottom *= fact[c / 2];
    bottom %= MOD;
  }
  cout << (top * inverse_mod(bottom) % MOD);
}
