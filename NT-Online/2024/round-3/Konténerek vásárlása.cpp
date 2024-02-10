#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  int n;
  cin >> n;
  vector<array<int, 2>> x(n);
  for (auto& [t, e] : x) cin >> t >> e;

  set<int> s;
  int cost = 0;
  array<int, 2> best = {0, 0}, best_inds = {-1, -1};
  for (int l = 0, r = 0; r < n; r++) {
    while (s.count(x[r][0])) {
      s.erase(x[l][0]);
      cost -= x[l][1];
      l++;
    }
    s.insert(x[r][0]);
    cost += x[r][1];
    array<int, 2> curr = {(int)s.size(), -cost};
    if (curr > best) {
      best = curr;
      best_inds = {l, r};
    }
  }
  cout << best_inds[0] + 1 << ' ' << best_inds[1] + 1;
}
