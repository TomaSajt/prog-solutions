#include <bits/stdc++.h>
using namespace std;
const int mod = 32609;

vector<vector<int>> g;
vector<int> par, sub_size;

void dfs(int u) {
  sub_size[u] = 1;
  for (int v : g[u]) {
    if (v == par[u]) continue;
    par[v] = u;
    dfs(v);
    sub_size[u] += sub_size[v];
  }
}

int main() {
  cin.tie(0), ios::sync_with_stdio(0);

  int n;
  cin >> n;

  g.resize(n + 1);
  par.resize(n + 1);
  sub_size.resize(n + 1);

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1);

  vector<array<int, 3>> edges;
  for (int i = 2; i <= n; i++) {
    int ss = sub_size[i];
    edges.push_back({ss * (n - ss) * 2, i, par[i]});
  }
  sort(edges.begin(), edges.end());

  vector<int> costs(n - 1);
  for (int& c : costs) cin >> c;
  sort(costs.begin(), costs.end());

  int res = 0;
  for (int i = 0; i < n - 1; i++) {
    res += (edges[i][0] % mod) * (costs[i] % mod);
    res %= mod;
  }
  cout << res << '\n';
  for (int i = 0; i < n - 1; i++) {
    cout << edges[i][1] << ' ' << edges[i][2] << ' ' << costs[i] << '\n';
  }
}
