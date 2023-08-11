#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ll n, x;
  cin >> n >> x;
  vector<ll> v(n);

  for (ll& i : v) cin >> i;

  map<ll, pair<int, int>> hash;

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (hash.count(x - v[i] - v[j])) {
        auto [a, b] = hash[x - v[i] - v[j]];
        cout << a + 1 << ' ' << b + 1 << ' ' << i + 1 << ' ' << j + 1;
        return 0;
      }
    }
    for (int h = 0; h < i; h++) {
      hash[v[h] + v[i]] = {h, i};
    }
  }
  cout << "IMPOSSIBLE" << endl;
}
