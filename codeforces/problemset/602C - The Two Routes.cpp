#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<bool>> adj(n + 1, vector<bool>(n + 1));
  while (m--) {
    int u, v;
    cin >> u >> v;
    adj[u][v] = 1;
    adj[v][u] = 1;
  }
  if (adj[1][n]) {
    for (int u = 1; u <= n; u++) {
      for (int v = u + 1; v <= n; v++) {
        adj[u][v] = !adj[u][v];
        adj[v][u] = !adj[v][u];
      }
    }
  }

  queue<int> q;
  vector<int> dist(n + 1, -1);
  dist[1] = 0;
  q.push(1);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    if (u == n) break;
    for (int v = 1; v <= n; v++) {
      if (!adj[u][v]) continue;
      if (dist[v] != -1) continue;
      dist[v] = dist[u] + 1;
      q.push(v);
    }
  }
  cout << dist[n];
}
