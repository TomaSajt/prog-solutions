#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<vector<int>> comps;
vector<bool> vis;

void dfs(int u) {
  vis[u] = 1;
  comps.back().push_back(u);
  for (int v : g[u]) {
    if (!vis[v]) dfs(v);
  }
}

int main() {
  int n, m;
  cin >> n >> m;

  g.resize(n + 1);
  while (m--) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v), g[v].push_back(u);
  }

  vis.resize(n + 1);
  for (int u = 1; u <= n; u++) {
    if (vis[u]) continue;
    comps.push_back({});
    dfs(u);
  }

  cout << comps.size() << '\n';
  for (auto& comp : comps) {
    sort(comp.begin(), comp.end());
    for (int u : comp) cout << u << ' ';
    cout << '\n';
  }
}
