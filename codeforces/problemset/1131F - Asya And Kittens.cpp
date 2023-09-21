#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> children;
vector<int> parent, depth;

int find_root(int u) {
  return parent[u] == u ? u : find_root(parent[u]);
}

void merge(int u, int v) {
  u = find_root(u), v = find_root(v);
  assert(u != v);
  if (depth[u] < depth[v]) swap(u, v);
  if (depth[u] == depth[v]) depth[u]++;
  parent[v] = u;
  children[u].push_back(v);
}

void traverse(int u) {
  cout << u << ' ';
  for (int v : children[u]) traverse(v);
}

int main() {
  cin.tie(0), ios::sync_with_stdio(0);

  int n;
  cin >> n;

  children.resize(n + 1);
  parent.resize(n + 1);
  iota(parent.begin(), parent.end(), 0);
  depth.resize(n + 1, 1);

  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    merge(a, b);
  }

  traverse(find_root(1));
}
