#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> dist;

void dfs(int u) {
  for (int v : g[u]) {
    if (dist[v] != -1) continue;
    dist[v] = dist[u] + 1;
    dfs(v);
  }
}

int main() {
  int n;
  cin >> n;
  g.resize(n + 1);
  dist.resize(n + 1, -1);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dist[1] = 0;
  dfs(1);
  int start = max_element(dist.begin() + 1, dist.end()) - dist.begin();
  dist.assign(n + 1, -1);
  dist[start] = 0;
  dfs(start);
  cout << *max_element(dist.begin() + 1, dist.end());
}
