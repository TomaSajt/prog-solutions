#include <bits/stdc++.h>
using namespace std;

int solve(const vector<int>& v) {
  int best = 1;
  int curr = 1;
  for (int i = 1; i < v.size(); i++) {
    if (v[i] != v[i - 1]) curr = 0;
    curr++;
    best = max(best, curr);
  }
  return best;
}

int main() {
  cin.tie(0), ios::sync_with_stdio(0);

  int m, n, p;
  cin >> m >> n >> p;

  int sol1 = 0, sol2 = 0;
  while (m--) {
    vector<int> v(n);
    for (int& a : v) cin >> a;
    sol2 = max(sol2, solve(v));
    sort(v.begin(), v.end());
    if (solve(v) > n / 2) sol1++;
  }

  cout << sol1 << '\n';
  cout << sol2;
}
