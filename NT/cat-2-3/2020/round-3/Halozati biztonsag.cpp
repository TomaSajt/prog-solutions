#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n, m, k;
  cin >> n >> m >> k;
  vector<set<int>> g(n + 1);
  while (m--) {
    int u, v;
    cin >> u >> v;
    g[u].insert(v);
    g[v].insert(u);
  }
  queue<int> bad;
  for (int i = 1; i <= n; i++) {
    if (g[i].size() < k)
      bad.push(i);
  }
  while (!bad.empty()) {
    int u = bad.front();
    bad.pop();
    for (int v : g[u]) {
      g[v].erase(u);
      if (g[v].size() < k)
        bad.push(v);
    }
  }
  vector<int> res;
  for (int i = 1; i <= n; i++) {
    if (g[i].size() >= k)
      res.push_back(i);
  }
  cout << res.size() << '\n';
  for (auto &u : res)
    cout << u << ' ';
}
