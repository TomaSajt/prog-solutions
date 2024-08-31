#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n + 1, vector<int>(m + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) cin >> a[i][j];
  }

  int bstart = (n + 1) / 2 + 1;
  set<int> bset;

  for (int i = bstart; i <= n; i++) {
    for (int j = 1; j <= m; j++) bset.insert(a[i][j]);
  }
  int q;
  cin >> q;
  while (q--) {
    int e;
    cin >> e;
    if (e == 2) {
      int w;
      cin >> w;
      continue;
    }
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    if (e == 1) {
      if (r1 > r2) {
        swap(r1, r2);
        swap(c1, c2);
      }
      if (r1 < bstart && r2 >= bstart) {
        bset.erase(a[r2][c2]);
        bset.insert(a[r1][c1]);
      }
      swap(a[r1][c1], a[r2][c2]);
    }
    else {
      if (bset.empty()) cout << "-1\n";
      else cout << *bset.begin() << '\n';
    }
  }
}
