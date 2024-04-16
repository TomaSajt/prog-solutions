#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<vector<int>> g;
vector<set<int>> sets;
vector<int> vals, mexes;

void dfs(int u) {
  sets[u].insert(vals[u]);
  for (int v : g[u]) {
    dfs(v);
    mexes[u] = max(mexes[u], mexes[v]);
    if (sets[u].size() < sets[v].size()) swap(sets[u], sets[v]);
    sets[u].insert(sets[v].begin(), sets[v].end());
  }
  auto it = sets[u].lower_bound(mexes[u]);
  while (it != sets[u].end() && *it == mexes[u]) mexes[u]++, it++;
}

signed main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n;
  cin >> n;
  g.resize(n + 1);
  sets.resize(n + 1);
  mexes.resize(n + 1, 1);
  vals.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    int p;
    cin >> p;
    g[p].push_back(i);
  }
  for (int i = 1; i <= n; i++) cin >> vals[i];
  dfs(1);
  for (int i = 1; i <= n; i++) cout << mexes[i] << ' ';
}
