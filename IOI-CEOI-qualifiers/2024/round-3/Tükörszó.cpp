#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<vector<int>> g;
vector<int> color, parent, depth;

int get_root(int u) {
  if (u == parent[u]) return u;
  return parent[u] = get_root(parent[u]);
}

vector<array<int, 2>> sol;

void merge(int u, int v, bool init) {
  u = get_root(u), v = get_root(v);
  if (u == v) return;
  if (!init) assert(color[u] != color[v]);
  if (depth[u] < depth[v]) swap(u, v);
  if (depth[u] == depth[v]) depth[u]++;
  int c1 = min(color[u], color[v]);
  int c2 = max(color[u], color[v]);
  color[u] = c1;
  parent[v] = u;
  if (init) return;
  sol.push_back({c2, c1});
}

signed main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n;
  cin >> n;
  parent.resize(n + 1);
  iota(parent.begin(), parent.end(), 0);
  depth.assign(n + 1, 1);
  color.resize(n + 1);
  map<int, int> col_map;
  for (int i = 1; i <= n; i++) {
    cin >> color[i];
    if (col_map.count(color[i])) {
      merge(col_map[color[i]], i, true);
    }
    else {
      col_map[color[i]] = i;
    }
  }

  for (int i = 1; i <= n; i++) {
    int j = n - i + 1;
    if (j <= i) break;
    merge(i, j, false);
  }

  cout << sol.size() << endl;
  for (auto [a, b] : sol) cout << a << ' ' << b << '\n';
}
