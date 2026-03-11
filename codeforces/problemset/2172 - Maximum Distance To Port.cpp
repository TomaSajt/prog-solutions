#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  int n, m, k;
  cin >> n >> m >> k;

  vector<vector<int>> g(n + 1);
  vector<int> t(n + 1), d(n + 1, -1), r(k + 1, -1);

  for (int u = 1; u <= n; u++) cin >> t[u];
  while (m--) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  queue<int> q;
  q.push(1);
  d[1] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v : g[u]) {
      if (d[v] != -1) continue;
      d[v] = d[u] + 1;
      q.push(v);
    }
  }
  for (int u = 1; u <= n; u++) {
    r[t[u]] = max(r[t[u]], d[u]);
  }
  for (int i = 1; i <= k; i++) {
    cout << r[i] << ' ';
  }
}
