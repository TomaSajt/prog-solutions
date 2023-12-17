#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = LLONG_MAX / 2; // half, because we might need to do INF+INF without overflowing

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n, m, q;
  cin >> n >> m >> q;
  vector<vector<ll>> g(n + 1, vector<ll>(n + 1, INF));
  while (m--) {
    int u, v;
    ll w;
    cin >> u >> v >> w;
    g[u][v] = g[v][u] = min(g[u][v], w); // if multiple edges, keep lowest cost
  }

  for (int i = 1; i <= n; i++) {
    g[i][i] = 0;
  }
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
      }
    }
  }

  while (q--) {
    int u, v;
    cin >> u >> v;
    cout << (g[u][v] == INF ? -1ll : g[u][v]) << endl;
  }
}
