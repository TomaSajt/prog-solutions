#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
long long c[2];

void dfs(int u, int p, int r) {
  c[r]++;
  for (int v : g[u]) {
    if (v != p) dfs(v, u, 1 - r);
  }
}

int main() {
  int n;
  cin >> n;
  g.resize(n + 1);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1, -1, 0);
  cout << c[0] * c[1] - n + 1;
}
