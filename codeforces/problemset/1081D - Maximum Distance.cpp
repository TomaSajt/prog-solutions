#include <bits/stdc++.h>
using namespace std;
vector<int> par, dep, cnt;

int find(int u) {
  return u == par[u] ? u : par[u] = find(par[u]);
}

bool merge(int u, int v) {
  u = find(u), v = find(v);
  if (u == v) return 0;

  if (dep[u] < dep[v]) swap(u, v);
  if (dep[u] == dep[v]) dep[u]++;

  par[v] = u;
  cnt[u] += cnt[v];
  return 1;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  int n, m, k;
  cin >> n >> m >> k;

  vector<int> x(k);
  for (int& xi : x) cin >> xi;

  vector<array<int, 3>> edges(m);
  for (auto& [w, u, v] : edges) cin >> u >> v >> w;

  dep.resize(n + 1, 1);

  par.resize(n + 1);
  iota(par.begin(), par.end(), 0);

  cnt.resize(n + 1, 0);
  for (int& xi : x) cnt[xi] = 1;

  int sol = -1;
  sort(edges.begin(), edges.end());
  for (auto& [w, u, v] : edges) {
    if (merge(u, v) && cnt[find(u)] == k) {
      sol = w;
      break;
    }
  }

  while (k--) cout << sol << ' ';
}
