#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);

  int n, m;
  cin >> n >> m;

  vector<int> d(n + 1);
  while (m--) {
    int s, e;
    cin >> s >> e;
    d[s]++, d[e + 1]--;
  }

  vector<int> c(n + 1);
  partial_sum(d.begin(), d.end(), c.begin());

  int len = 0, best_len = 0, best_start;
  for (int i = n; i >= 1; i--) {
    if (c[i] != 0) {
      len = 0;
      continue;
    }
    len++;
    if (len >= best_len) {
      best_len = len;
      best_start = i;
    }
  }

  if (best_len == 0) {
    cout << "-1";
    return 0;
  }
  cout << best_len << ' ' << best_start;
}
