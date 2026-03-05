#include <bits/stdc++.h>
using namespace std;

vector<bool> started, done, is_back_edge;
vector<vector<array<int, 2>>> g;

void dfs(int u) {
  started[u] = true;
  for (auto [v, i] : g[u]) {
    if (!started[v]) dfs(v);
    else if (!done[v]) {
      is_back_edge[i] = true;
    }
  }
  done[u] = true;
}

int main() {
  int n, m;
  cin >> n >> m;
  g.resize(n + 1), started.resize(n + 1), done.resize(n + 1), is_back_edge.resize(m);

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back({v, i});
  }

  for (int i = 1; i <= n; i++) {
    if (!started[i]) dfs(i);
  }

  cout << (count(is_back_edge.begin(), is_back_edge.end(), true) > 0 ? 2 : 1)
       << endl;

  for (int i = 0; i < m; i++) {
    cout << (is_back_edge[i] ? 2 : 1) << " ";
  }
  cout << endl;
}
