#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(), cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> v(n);
  for (int& a : v) cin >> a;

  map<int, int> c;
  int best = -1;
  int best_i = -1;
  for (int i = 0; i < n; i++) {
    c[v[i]]++;
    if (i - k >= 0) {
      c[v[i - k]]--;
      if (c[v[i - k]] == 0) c.erase(v[i - k]);
    }
    if (i - k + 1 >= 0) {
      int low = INT_MAX, high = 0;
      for (auto [_, cnt] : c) {
        low = min(low, cnt);
        high = max(high, cnt);
      }
      if (high - low > best) {
        best = high - low;
        best_i = i - k + 1;
      }
    }
  }
  cout << best_i + 1;
}
