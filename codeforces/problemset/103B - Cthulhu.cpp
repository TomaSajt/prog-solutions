#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<bool> vis;
int fwd_bck_cnt = 0;

void dfs(int u, int p) {
  vis[u] = true;
  for (int v : g[u]) {
    if (vis[v]) {
      if (v != p) fwd_bck_cnt++;
      continue;
    }
    dfs(v, u);
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  g.resize(n + 1), vis.resize(n + 1);

  while (m--) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v), g[v].push_back(u);
  }

  dfs(1, -1);
  cout << (count(vis.begin() + 1, vis.end(), true) == n && fwd_bck_cnt == 2 ? "FHTAGN!\n" : "NO\n");
}
