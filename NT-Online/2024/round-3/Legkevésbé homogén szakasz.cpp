#include <bits/stdc++.h>
using namespace std;

int cnt[1001];
set<pair<int, int>> cnt_val_set;

void inc(int v, int c) {
  cnt_val_set.erase({cnt[v], v});
  cnt[v] += c;
  cnt_val_set.insert({cnt[v], v});
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  int n, k;
  cin >> n >> k;

  vector<int> x(n);
  for (int& xi : x) cin >> xi;

  int best = INT_MAX;
  int best_end = -1;
  for (int i = 0; i < n; i++) {
    inc(x[i], 1);
    if (i - k >= 0) inc(x[i - k], -1);
    if (i - k + 1 >= 0) {
      int c = cnt_val_set.rbegin()->first;
      if (c < best) {
        best = c;
        best_end = i;
      }
    }
  }
  cout << best_end - k + 2;
}
