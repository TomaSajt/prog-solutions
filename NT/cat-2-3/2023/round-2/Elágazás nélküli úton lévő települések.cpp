#include <bits/stdc++.h>
using namespace std;

set<int> sol;
vector<vector<int>> g;

void dfs(int u, int p) {
  for (int v : g[u]) {
    if (v == p) continue;
    sol.insert(v);
    if (g[v].size() >= 3) continue;
    dfs(v, u);
  }
}
int main() {
  cin.tie(0), ios::sync_with_stdio(0);

  int n, m;
  cin >> n >> m;
  g.resize(n + 1);

  while (m--) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  for (int i = 1; i <= n; i++) {
    if (g[i].size() == 1) dfs(i, 0);
  }

  cout << sol.size() << '\n';
  for (int i : sol) cout << i << ' ';
}
