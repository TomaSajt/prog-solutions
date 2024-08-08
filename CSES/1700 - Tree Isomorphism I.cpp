#include <bits/stdc++.h>
using namespace std;

int get_id(vector<vector<int>>& g, map<vector<int>, int>& cti, int u, int p) {
  vector<int> c;
  for (int v : g[u]) {
    if (v != p) c.push_back(get_id(g, cti, v, u));
  }
  sort(c.begin(), c.end());
  if (cti.count(c)) return cti[c];
  return cti[c] = cti.size();
}

void solve() {
  int n;
  cin >> n;

  vector<vector<int>> g1(n + 1), g2(n + 1);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    g1[u].push_back(v);
    g1[v].push_back(u);
  }
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    g2[u].push_back(v);
    g2[v].push_back(u);
  }
  map<vector<int>, int> cti;
  int a = get_id(g1, cti, 1, 0);
  int b = get_id(g2, cti, 1, 0);
  cout << (a == b ? "YES" : "NO") << '\n';
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
