#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;

vector<int> d, l;

int t = 1;

set<int> nodes;

void dfs(int u) {
  d[u] = l[u] = t++;
  int c = 0;
  for (int v : g[u]) {
    if (d[v]) {
      l[u] = min(l[u], d[v]);
    }
    else {
      dfs(v);
      l[u] = min(l[u], l[v]);
      if (u == 1) c++;
      if (u != 1 && d[u] <= l[v]) {
        nodes.insert(u);
      }
    }
  }
  if (c >= 2) nodes.insert(1);
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

  dfs(1);

  cout << nodes.size() << '\n';
  for (int a : nodes) cout << a << ' ';
}
