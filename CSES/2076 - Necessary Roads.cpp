#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;

vector<int> d, l;

int t = 1;

vector<array<int, 2>> edges;

void dfs(int u, int p) {
  d[u] = t++;
  l[u] = d[u];
  for (int v : g[u]) {
    if (v == p) continue;
    if (d[v]) {
      l[u] = min(l[u], d[v]);
    }
    else {
      dfs(v, u);
      l[u] = min(l[u], l[v]);
      if (d[u] < l[v]) {
        edges.push_back({u, v});
      }
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  g.resize(n + 1);
  d.resize(n + 1), l.resize(n + 1);

  while (m--) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  dfs(1, 0);

  cout << edges.size() << '\n';
  for (auto [a, b] : edges) cout << a << ' ' << b << endl;
}
