#include <bits/stdc++.h>
using namespace std;

int depth(int u, vector<vector<int>> const& ch) {
  int res = 0;
  for (int v : ch[u]) {
    res = max(res, depth(v, ch));
  }
  return res + 1;
}

int main() {
  int n;
  cin >> n;

  vector<int> par(n + 1);
  vector<vector<int>> ch(n + 1);
  for (int u = 1; u <= n; u++) {
    cin >> par[u];
    if (par[u] != -1)
      ch[par[u]].push_back(u);
  }

  int res = 0;
  for (int u = 1; u <= n; u++) {
    if (par[u] == -1) {
      res = max(res, depth(u, ch));
    }
  }

  cout << res << '\n';
}
