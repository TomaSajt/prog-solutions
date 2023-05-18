#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> d, l;
set<int> res;

int t = 0;

void dfs(int u) {
  d[u] = l[u] = ++t;
  for (auto &v : g[u]) {
    if (d[v]) {
      l[u] = min(l[u], d[v]);
      continue;
    }
    dfs(v);
    l[u] = min(l[u], l[v]);
    if (l[v] >= d[u]) res.insert(u);
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  g.resize(n + 2), d.resize(n + 2), l.resize(n + 2);
  vector<int> in_deg(n + 1), out_deg(n + 1);
  while (m--) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v), g[v].push_back(u);
    out_deg[u]++, in_deg[v]++;
  }
  for (int i = 1; i <= n; i++) {
    if (in_deg[i] == 0) g[0].push_back(i), g[i].push_back(0);
    if (out_deg[i] == 0) g[n + 1].push_back(i), g[i].push_back(n + 1);
  }
  dfs(0);

  res.erase(0), res.erase(n + 1);
  cout << res.size() << '\n';
  for (auto &r : res) cout << r << ' ';
  return 0;
}
