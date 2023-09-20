#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> dist_to;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  int n, m;
  cin >> n >> m;

  vector<vector<dist_to>> g(2 * n + 1);
  while (m--) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].push_back({w, v});
    g[u + n].push_back({w, v + n});
    g[u].push_back({w / 2, v + n});
  }

  priority_queue<dist_to, vector<dist_to>, greater<dist_to>> pq;
  vector<ll> dist(2 * n + 1, LLONG_MAX / 2);
  dist[1] = 0;
  pq.push({0, 1});

  while (!pq.empty()) {
    auto [d, u] = pq.top();
    pq.pop();
    if (u == 2 * n) break; // reached the end
    if (d != dist[u]) continue; // discard outdated entries
    for (auto& [w, v] : g[u]) {
      if (dist[u] + w >= dist[v]) continue;
      dist[v] = dist[u] + w;
      pq.push({dist[v], v});
    }
  }

  cout << dist[2 * n];
}
