#include <bits/stdc++.h>
using namespace std;

vector<int> parent, depth, comp_size;
int best_size = 1;

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
  comp_size[u] += comp_size[v];
  best_size = max(best_size, comp_size[u]);
  return true;
}

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  parent.resize(n + 1);
  iota(parent.begin(), parent.end(), 0);
  depth.resize(n + 1, 1);
  comp_size.resize(n + 1, 1);
  int comps = n;
  while (m--) {
    int u, v;
    cin >> u >> v;
    if (try_merge(u, v))
      comps--;
    cout << comps << ' ' << best_size << '\n';
  }
}
