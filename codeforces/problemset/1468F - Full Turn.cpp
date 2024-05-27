#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  map<array<int, 2>, int> slope_cnts;
  long long res = 0;
  for (int i = 0; i < n; i++) {
    int x, y, u, v;
    cin >> x >> y >> u >> v;
    int dx = x - u, dy = y - v;
    int g = gcd(dx, dy);
    dx /= g, dy /= g;
    res += slope_cnts[{-dx, -dy}];
    slope_cnts[{dx, dy}]++;
  }
  cout << res << '\n';
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
}
