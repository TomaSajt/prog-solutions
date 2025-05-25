#include <bits/stdc++.h>
#define int int64_t
using namespace std;

vector<int> parent, depth;

int find(int u) {
  if (parent[u] == u)
    return u;
  return parent[u] = find(parent[u]);
}

bool try_merge(int u, int v) {
  u = find(u), v = find(v);
  if (u == v)
    return false;
  if (depth[u] < depth[v])
    swap(u, v);
  parent[v] = u;
  if (depth[u] == depth[v])
    depth[u]++;
  return true;
}

int32_t main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n, m, k;
  cin >> n >> m >> k;

  parent.resize(n + 1);
  iota(parent.begin(), parent.end(), 0);
  depth.resize(n + 1, 1);

  vector<array<int, 3>> edges(m);

  for (auto& [w, u, v] : edges) {
    cin >> u >> v >> w;
  }

  sort(edges.begin(), edges.end());

  int res = 0;
  for (auto& [w, u, v] : edges) {
    if (u == 1 || v == 1) {
      assert(try_merge(u, v));
      res += w;
    }
  }

  for (auto& [w, u, v] : edges) {
    if (u == 1 || v == 1) continue;
    if (try_merge(u, v)) {
      res += w;
    }
  }

  cout << res;
}
